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

#main.dvi: main.tex
#	latex -shell-escape main.tex
#	latex -shell-escape main.tex

#%.dvi: %.tex
#	latex -shell-escape $<

#%.ps: %.dvi
#	dvips $<

#%.pdf: %.ps
#	ps2pdf $<

%.pdf: %.tex
	pdflatex -shell-escape $<
	pdflatex -shell-escape $<

clean:
	rm -f *.aux *.pdf $(AUX) $(DVI) $(PS) $(PDF) $(AUX) $(LOG) $(SNM) $(OUT) $(NAV) $(TOC) $(BBL) $(BLG) $(LOF) $(LOT) *~

open:
	emacs *.tex &

read:
	evince main.pdf &

tar:	clean
	tar cvf ../rapport.tar ../rapport/
	gzip ../rapport.tar

.PHONY: clean
