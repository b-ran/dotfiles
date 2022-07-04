void
togglecolorseltag()
{
	selmon->colorseltag = !selmon->colorseltag;
	drawbar(selmon);
}