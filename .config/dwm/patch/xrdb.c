void
loadxrdb()
{
	Display *display;
	char * resm;
	XrmDatabase xrdb;
	char *type;
	XrmValue value;

	display = XOpenDisplay(NULL);

	if (display != NULL) {
		resm = XResourceManagerString(display);

		if (resm != NULL) {
			xrdb = XrmGetStringDatabase(resm);

			if (xrdb != NULL) {
				XRDB_LOAD_COLOR("dwm.normfgcolor", normfgcolor);
				XRDB_LOAD_COLOR("dwm.normbgcolor", normbgcolor);
				XRDB_LOAD_COLOR("dwm.normbordercolor", normbordercolor);
				XRDB_LOAD_COLOR("dwm.normfloatcolor", normfloatcolor);
				XRDB_LOAD_COLOR("dwm.selfgcolor", selfgcolor);
				XRDB_LOAD_COLOR("dwm.selbgcolor", selbgcolor);
				XRDB_LOAD_COLOR("dwm.selbordercolor", selbordercolor);
				XRDB_LOAD_COLOR("dwm.selfloatcolor", selfloatcolor);
				XRDB_LOAD_COLOR("dwm.titlenormfgcolor", titlenormfgcolor);
				XRDB_LOAD_COLOR("dwm.titlenormbgcolor", titlenormbgcolor);
				XRDB_LOAD_COLOR("dwm.titlenormbordercolor", titlenormbordercolor);
				XRDB_LOAD_COLOR("dwm.titlenormfloatcolor", titlenormfloatcolor);
				XRDB_LOAD_COLOR("dwm.titleselfgcolor", titleselfgcolor);
				XRDB_LOAD_COLOR("dwm.titleselbgcolor", titleselbgcolor);
				XRDB_LOAD_COLOR("dwm.titleselbordercolor", titleselbordercolor);
				XRDB_LOAD_COLOR("dwm.titleselfloatcolor", titleselfloatcolor);
				XRDB_LOAD_COLOR("dwm.tagsnormfgcolor", tagsnormfgcolor);
				XRDB_LOAD_COLOR("dwm.tagsnormbgcolor", tagsnormbgcolor);
				XRDB_LOAD_COLOR("dwm.tagsnormbordercolor", tagsnormbordercolor);
				XRDB_LOAD_COLOR("dwm.tagsnormfloatcolor", tagsnormfloatcolor);
				XRDB_LOAD_COLOR("dwm.tagsselfgcolor", tagsselfgcolor);
				XRDB_LOAD_COLOR("dwm.tagsselbgcolor", tagsselbgcolor);
				XRDB_LOAD_COLOR("dwm.tagsselbordercolor", tagsselbordercolor);
				XRDB_LOAD_COLOR("dwm.tagsselfloatcolor", tagsselfloatcolor);
				XRDB_LOAD_COLOR("dwm.hidnormfgcolor", hidnormfgcolor);
				XRDB_LOAD_COLOR("dwm.hidnormbgcolor", hidnormbgcolor);
				XRDB_LOAD_COLOR("dwm.hidselfgcolor", hidselfgcolor);
				XRDB_LOAD_COLOR("dwm.hidselbgcolor", hidselbgcolor);
				XRDB_LOAD_COLOR("dwm.urgfgcolor", urgfgcolor);
				XRDB_LOAD_COLOR("dwm.urgbgcolor", urgbgcolor);
				XRDB_LOAD_COLOR("dwm.urgbordercolor", urgbordercolor);
				XRDB_LOAD_COLOR("dwm.urgfloatcolor", urgfloatcolor);
				XRDB_LOAD_COLOR("dwm.tags.fg1", tag1fgcolor);
				XRDB_LOAD_COLOR("dwm.tags.bg1", tag1bgcolor);
				XRDB_LOAD_COLOR("dwm.tags.fg2", tag2fgcolor);
				XRDB_LOAD_COLOR("dwm.tags.bg2", tag2bgcolor);
				XRDB_LOAD_COLOR("dwm.tags.fg3", tag3fgcolor);
				XRDB_LOAD_COLOR("dwm.tags.bg3", tag3bgcolor);
				XRDB_LOAD_COLOR("dwm.tags.fg4", tag4fgcolor);
				XRDB_LOAD_COLOR("dwm.tags.bg4", tag4bgcolor);
				XRDB_LOAD_COLOR("dwm.tags.fg5", tag5fgcolor);
				XRDB_LOAD_COLOR("dwm.tags.bg5", tag5bgcolor);
				XRDB_LOAD_COLOR("dwm.tags.fg6", tag6fgcolor);
				XRDB_LOAD_COLOR("dwm.tags.bg6", tag6bgcolor);
				XRDB_LOAD_COLOR("dwm.tags.fg7", tag7fgcolor);
				XRDB_LOAD_COLOR("dwm.tags.bg7", tag7bgcolor);
				XRDB_LOAD_COLOR("dwm.tags.fg8", tag8fgcolor);
				XRDB_LOAD_COLOR("dwm.tags.bg8", tag8bgcolor);
				XRDB_LOAD_COLOR("dwm.tags.fg9", tag9fgcolor);
				XRDB_LOAD_COLOR("dwm.tags.bg9", tag9bgcolor);
				XRDB_LOAD_COLOR("dwm.tags.layoutfg", layoutfgcolor);
				XRDB_LOAD_COLOR("dwm.tags.layoutbg", layoutbgcolor);

				XrmDestroyDatabase(xrdb);
			}
		}
	}

	XCloseDisplay(display);
}

void
xrdb(const Arg *arg)
{
	loadxrdb();
	int i;
	for (i = 0; i < LENGTH(colors); i++)
		scheme[i] = drw_scm_create(drw, colors[i],
		ColCount
		);
	focus(NULL);
	arrange(NULL);
}

