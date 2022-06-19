// appearance
static const unsigned int borderpx       = 1;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int statusmon               = 'A'; /* Status shown on: -1 (all monitors), 0 (a specific monitor), 'A' (active monitor) */

// VANITYGAPS_PATCH
static const unsigned int gappih         = 20;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 30;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */

//  BAR_SYSTRAY_PATCH
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */

// BAR_UNDERLINETAGS_PATCH
static const unsigned int ulinepad = 5;         /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke  = 2;     /* thickness / height of the underline */
static const unsigned int ulinevoffset = 0;     /* how far above the bottom of the bar the line should appear */
static const int ulineall = 0;                  /* 1 to show underline on all tags, 0 for just the active ones */


/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;


static const char *fonts[]               = { "JetBrainsMono Nerd Font Mono:style=Medium:size=13" };
static const char dmenufont[]            = "JetBrainsMono Nerd Font Mono:style=Medium:size=13";

static char c000000[]                    = "#000000"; /* placeholder value */

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";


static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

// COOL_AUTOSTART_PATCH
static const char *const autostart[] = {
	"bash", NULL,
	"sxhkd", NULL,
	"picom", NULL,
	"dwmblocks", NULL,
	NULL /* terminate */
};

static char *tagicons[][NUMTAGS] = {
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Firefox", .tags = 1 << 7)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                drawfunc                clickfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,              draw_tags,              click_tags,              "tags" }, // BAR_TAGS_PATCH
	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,           draw_systray,           click_systray,           "systray" }, // BAR_SYSTRAY_PATCH
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,          draw_ltsymbol,          click_ltsymbol,          "layout" }, // BAR_LTSYMBOL_PATCH
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,          draw_status2d,          click_statuscmd,         "status2d" }, // BAR_STATUS2D_PATCH BAR_STATUSCMD_PATCH
	{ -1,        0,     BAR_ALIGN_NONE,   width_awesomebar,        draw_awesomebar,        click_awesomebar,        "awesomebar" }, // BAR_AWESOMEBAR_PATCH
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[@]",      spiral },
	{ "HHH",      grid },
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "[\\]",     dwindle },
	{ "|M|",      centeredmaster },
	{ "|||",      col },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL }, // CYCLELAYOUTS_PATCH
};


/* key definitions */
#define MODKEY Mod4Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      combotag,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0";
static const char *termcmd[]  = { "bash", NULL };
#define STATUSBAR "dwmblocks"


static Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_Return,     spawn,                  {.v = termcmd } },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY|ControlMask,           XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY|ControlMask,           XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY|ControlMask,           XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY|ControlMask,           XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },
    { MODKEY,                       XK_Tab,        view,                   {0} },
    { MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	{ MODKEY,                       XK_c,          killclient,             {0} },

	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_s,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_g,          setlayout,              {.v = &layouts[2]} },
	{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,      setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },

    { MODKEY|ControlMask,           XK_z,          showhideclient,          {0} }, // BAR_WINTITLEACTIONS_PATCH
	{ MODKEY|ControlMask,           XK_space,      focusmaster,             {0} }, // FOCUSMASTER_PATCH
	{ MODKEY|ShiftMask,             XK_q,          quit,                    {1} }, //RESTARTSIG_PATCH
	{ MODKEY|ShiftMask,             XK_F5,         xrdb,                    {.v = NULL } }, // XRDB_PATCH
	{ MODKEY,                       XK_f,          fullscreen,              {0} }, // FULLSCREEN_PATCH

    // CYCLELAYOUTS_PATCH
    { MODKEY|ControlMask,           XK_comma,      cyclelayout,            {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period,     cyclelayout,            {.i = +1 } },

	//FOCUSDIR_PATCH
	{ MODKEY,                       XK_Left,       focusdir,               {.i = 0 } }, // left
	{ MODKEY,                       XK_Right,      focusdir,               {.i = 1 } }, // right
	{ MODKEY,                       XK_Up,         focusdir,               {.i = 2 } }, // up
	{ MODKEY,                       XK_Down,       focusdir,               {.i = 3 } }, // down

	// PUSH_PATCH
	{ MODKEY,                       XK_j,          pushdown,               {0} },
	{ MODKEY,                       XK_k,          pushup,                 {0} },

	// VANITYGAPS_PATCH
	{ MODKEY|ControlMask,              XK_u,          incrgaps,             {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_u,          incrgaps,             {.i = -1 } },
	{ MODKEY|ControlMask,              XK_i,          incrigaps,            {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_i,          incrigaps,            {.i = -1 } },
	{ MODKEY|ControlMask,              XK_o,          incrogaps,            {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_o,          incrogaps,            {.i = -1 } },
	{ MODKEY|ControlMask,              XK_6,          incrihgaps,           {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_6,          incrihgaps,           {.i = -1 } },
	{ MODKEY|ControlMask,              XK_7,          incrivgaps,           {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_7,          incrivgaps,           {.i = -1 } },
	{ MODKEY|ControlMask,              XK_8,          incrohgaps,           {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_8,          incrohgaps,           {.i = -1 } },
	{ MODKEY|ControlMask,              XK_9,          incrovgaps,           {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_9,          incrovgaps,           {.i = -1 } },
	{ MODKEY|ControlMask,              XK_0,          togglegaps,           {0} },
	{ MODKEY|ControlMask|ShiftMask,    XK_0,          defaultgaps,          {0} },

	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};

/* button definitions */
static Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },

	// BAR_WINTITLEACTIONS_PATCH
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },

	// BAR_STATUSCMD_PATCH && BAR_DWMBLOCKS_PATCH
	{ ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 1 } },
	{ ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 2 } },
	{ ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 3 } },

	{ ClkClientWin,         MODKEY,              Button1,        moveorplace,    {.i = 1} }, // PLACEMOUSE_PATCH
	{ ClkClientWin,         MODKEY|ShiftMask,    Button1,        dragmfact,      {0} }, // DRAGCFACT_PATCH
};
