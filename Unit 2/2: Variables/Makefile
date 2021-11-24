NASM       = /usr/local/bin/nasm
LD           = ld

NASM_FLAGS = -f macho64
LD_FLAGS     = -static

SOURCES = $(basename $(wildcard *.asm))
OBJECTS = $(addsuffix .o, $(SOURCES))

OUTPUT = variables.exec

.PHONY: clean
clean: 
	rm -rf $(OBJECTS)
	rm -rf $(OUTPUT)

.PHONY: build
build: $(OUTPUT) 

.PHONY: run
run: build
	"./$(OUTPUT)"


$(OBJECTS): %.o: %.asm
	$(NASM) $(NASM_FLAGS) $<

$(OUTPUT): $(OBJECTS)
	$(LD) $(LD_FLAGS) $< -o $@