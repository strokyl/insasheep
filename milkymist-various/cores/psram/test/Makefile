SOURCES=tb_psram.v $(wildcard ../rtl/*.v) $(wildcard ./psram/*.v) $(wildcard ./unisims/*.v)

all: tb_psram

isim: tb_psram
	./tb_pstam

cversim: $(SOURCES)
	cver $(SOURCES)

clean:
	rm -f tb_psram verilog.log psram.vcd

tb_psram: $(SOURCES)
	iverilog -o $@ -I./psram -Dsg708 -s glbl -s $@ $(SOURCES)

.PHONY: clean sim cversim
