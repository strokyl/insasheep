TEX=main.tex

DVI=$(TEX:.tex=.dvi)
PS=$(TEX:.tex=.ps)
PDF=$(TEX:.tex=.pdf)
AUX=$(TEX:.tex=.aux)
LOG=$(TEX:.tex=.log)
SNM=$(TEX:.tex=.snm)
OUT=$(TEX:.tex=.out)
NAV=$(TEX:.tex=.nav)
TOC=$(TEX:.tex=.toc)
BBL=$(TEX:.tex=.bbl)
BLG=$(TEX:.tex=.blg)
LOF=$(TEX:.tex=.lof)
LOT=$(TEX:.tex=.lot)

all: $(PDF)

main.dvi: main.tex
	latex main.tex
	latex main.tex

%.dvi: %.tex
	latex $<

%.ps: %.dvi
	dvips $<

%.pdf: %.ps
	ps2pdf $<

#%.pdf: %.tex
#	pdflatex $<

clean:
	rm -f *.aux *.pdf $(AUX) $(DVI) $(PS) $(PDF) $(AUX) $(LOG) $(SNM) $(OUT) $(NAV) $(TOC) $(BBL) $(BLG) $(LOF) $(LOT) *~

read:
	evince main.pdf &

.PHONY: clean
