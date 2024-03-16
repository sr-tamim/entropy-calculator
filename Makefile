# if $CXX is not set, guess default `cxx'. It has to be in system
CXX ?= cxx
# compile options
CXXFLAGS ?= -Os -Wall -Wpedantic -Wextra
# link options
LDFLAGS ?= -s

target      ?= debug
<<targets>> := debug release
# addons
with     ?= gmp
without  ?=
<<addons>> := gmp

# Echo function
<< := echo
ifneq ($(shell eval 'echo -e'),-e)
	<< += -e
endif

<<debug-dir>   = Debug
<<release-dir>>= Release
<<target>>     = $(firstword $(filter $(<<targets>>),$(target)))
ifeq ($(<<target>>),release)
	<<tdir>> = Release
else
	<<tdir>> = Debug
endif

# optional addons
<<with>>       = $(sort $(filter-out $(without),$(filter $(<<addons>>),$(with))))
# project configs
CXXFLAGS += -I$(PWD)/headers -I$(PWD)/

# rebuild on optional deps change
ifneq ($(filter gmp,$(<<with>>)),)
	ifneq ($(shell pkg-config --exists gmp gmpxx && echo exists),)
		PKGS += gmpxx gmp
		CFLAGS += -D_USE_GMP
	endif
endif

ifneq ($(PKGS),)
	CXXFLAGS += $(shell pkg-config --cflags $(PKGS))
	LDFLAGS += $(shell pkg-config --libs $(PKGS))
endif

<<sources>> := \
	main.cpp


<<objects>> := $(<<sources>>:%=obj/$(<<tdir>>)/%.o)

# Output file name
ifeq ($(filter $(shell uname -o),Msys Cygwin),)
	BINARY ?= entropy-calculator
else
	ifeq ($(MSYSTEM_CARCH),i686)
		BINARY ?= entropy-calculator.exe
	else
		BINARY ?= entropy-calculator64.exe
	endif
endif

<<bindep>> = bin/$(<<tdir>>)/.$(BINARY).dep
<<binpth>> = bin/$(<<tdir>>)/$(BINARY)
<<->> := $(shell mkdir -p $(dir $(<<binpth>>)))
# Use $(<<bindep>>) file to track backend change
<<depends>> = $(sort $(<<with>>))
ifneq ($(sort $(file < $(<<bindep>>))),$(<<depends>>))
	<<null>> := $(file  > $(<<bindep>>),$(<<depends>>))
endif
undefine <<depends>> <<null>> <<->>
# using some makefile sorcery

all: $(<<binpth>>)

obj/$(<<tdir>>)/%.o: %
	@$(<<) "  CXX\t" $(<:src/%=%)
	@mkdir -p $(shell dirname $(@))
	@$(CXX) -c $(<) -o $(@) $(CXXFLAGS)

$(<<binpth>>): $(<<objects>>)
	@if test -n "$(<<with>>)"; then $(<<) "WITH\t" $(<<with>>);fi
	@$(<<) "LINK\t" "$(BINARY)$(^:obj/%=\\n\\t + %)"
	@$(CXX) $(^) -o $(@) $(LDFLAGS)

install: $(<<binpth>>)
	install -Dm0755 $(<) $(DESTDIR)$(PREFIX)/$(BINDIR)/$(BINARY)

uninstall:
	sudo $(RM) -f $(DESTDIR)$(PREFIX)/$(BINDIR)/$(BINARY)

clean:
	@$(<<) "  RM\t" "$(BINARY)$(<<objects>>:obj/%=\\n\\t + %)"
	@$(RM) -f $(<<objects>>) $(<<binpth>>) $(<<bindep>>)

test: $(BINARY)
	./$(BINARY)

$(<<objects>>): $(<<bindep>>)
.PHONY: all clean install uninstall test
