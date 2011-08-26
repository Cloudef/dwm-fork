/*
 * config.h
 */

/* appearance */
static const char font[] = "erusfont 7";

#define NUMCOLORS 8

/*   border,   foreground ,background */
static const char colors[NUMCOLORS][ColLast][8] = {
   { "#010101", "#ffffff", "#121212" }, // 0 = normal
   { "#212121", "#010101", "#cc6600" }, // 1 = selected
   { "#ff6600", "#ffffff", "#ff6600" }, // 2 =
   { "#ffffff", "#00BFFF", "#dddddd" }, // 3 =
   { "#ffffff", "#0000ff", "#dddddd" }, // 4 =
   { "#ffffff", "#000000", "#ffff00" }, // 5 =
   { "#ffffff", "#cc3300", "#dddddd" }, // 6 =
   { "#ffffff", "#cccccc", "#313131" }, // 7 = Status area
};

static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool clicktofocus      = True;     /* Click to focus windows */
static const Bool autofocusmonitor  = True;     /* Auto focus monitors */
static const Bool alwaysdrawstatus  = True;     /* Draw status to both monitors? */

static const Bool systray_enable = True;
static const int systray_spacing = 2;
static const int status_height   = 0;

/* which monitor systray appears */
#define PRIMARY_MONITOR 0

/* display edges, similar to margins expect
 * everything gets affected */
static const Edge edges[] = {
   /* X   Y   W   H */
   {  0,  0,  0, 0 }, // 1
   {  0,  0,  0, 0 }, // 2
};

/* window area margins */
static const Edge margins[] = {
   /* X   Y   W   H */
   {  0,  0,  0, 10 }, // 1 NOTE: This adds the bottom bar cap
   {  0,  0,  0,  0 }, // 2 NOTE: Second monitor has no bar
};

/* tagging */
static const char *tags[] = { "東", "方", "P", "R", "O", "J", "E", "C", "T" };
Bool autohide             = False;

/* floating = floating window
 * widget   = window without border and statusbar
 * below    = always below
 * above    = always above
 * zombie   = do not take input
 * sticky   = stay on all tags
 */
/*             floating,widget,  below.   above,   zombie,  sticky */
#define NORMAL False,   False,   False,   False,   False,   False
#define FLOAT  True,    False,   False,   False,   False,   False
#define WIDGET True,    True,    False,   True,    False,   True
#define CONKY  True,    True,    True,    False,   True,    True
#define URXVTQ True,    False,   False,   True,    False,   True
#define DOCK   True,    True,    False,   True,    False,   True

static const Rule rules[] = {
	/* class      instance    title       tags mask     type           monitor */
   { "Gimp",     NULL,       NULL,       0,            FLOAT,         -1 },
   { "URxvt",    "URxvtq",   NULL,       0,            URXVTQ,         0 },
   { "Oblogout", NULL,       NULL,       0,            URXVTQ,         0 },
   { "MaCoPiX",  NULL,       NULL,       0,            WIDGET,         1 },
   { "Kupfer.py",NULL,       NULL,       0,            WIDGET,        -1 },
   { "dzen",     "dzen2",    NULL,       0,            CONKY,         -1 },
   { "Conky",    NULL,       NULL,       0,            CONKY,          1 },
   { "Cairo-dock", "cairo-dock", NULL,   0,            DOCK,           0 }, /* not used */
   { "URxvt",    NULL,       "rTorrent", 1 << 4,       NORMAL,         1 },
   { "URxvt",    NULL,       "SnowNews", 1 << 3,       NORMAL,         1 },
   { "URxvt",    NULL,       "MSN",      1 << 2,       NORMAL,         1 },
   { "URxvt",    NULL,       "IRSSI",    1 << 1,       NORMAL,         1 },
   { "OperaNext", NULL,      NULL,       0,            NORMAL,        -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

/* num of masters */
static const int nmaster = 2;

/* layouts */
static const Layout layouts[]  = {
    /* symbol     arrange function */
    { "[]=",      tile },
    { "[=]",      bstackhoriz },
    { "[#]" ,     grid },
    { "[||]" ,    bstack },
    { "><>",      NULL },
    { "[M]",      monocle },
    { .symbol = NULL, .arrange = NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run" , "-p" , "Run:" , "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *dvolminus[] = { "dvol", "-d", "1", NULL };
static const char *dvolplus[] = { "dvol", "-i", "1", NULL };
static const char *dvolmute[] = { "dvol", "-t", NULL };
static const char *kupfer[] = { "kupfer", NULL };
static const char *oblogout[] = { "oblogout", NULL };

static Key keys[] = {
   /* modifier                     key        function        argument */
   { 0,                            0x1008ff11,spawn,          {.v = dvolminus } },
   { 0,                            0x1008ff13,spawn,          {.v = dvolplus  } },
   { 0,                            0x1008ff12,spawn,          {.v = dvolmute  } },
   { 0,                            0x1008ff30,spawn,          {.v = termcmd   } },
   { 0,                            XK_section,spawn,         SHCMD("$HOME/.config/dwm/urxvtq") },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {.i = -1} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
   { ALTKEY,                       XK_s,      resizemouse,    {0} },
   { MODKEY,                       XK_s,      togglesticky,   {0} },
   { ALTKEY,                       XK_F2,     spawn,          {.v = kupfer} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
   { MODKEY,                       XK_KP_End,   nextlayout,     {0} },
   { MODKEY,                       XK_KP_Down,  prevlayout,     {0} },
 	{ MODKEY,                       XK_KP_Insert,cyclezoom,      {0} },
  	{ MODKEY,                       XK_KP_Delete,togglefloating,{0} },
	{ MODKEY,                       XK_KP_Home,  setmfact,     {.f = -0.05} },
	{ MODKEY,                       XK_KP_Up,    setmfact,     {.f = +0.05} },
 	{ MODKEY,                       XK_KP_Left,  focusstack,   {.i = +1 } },
	{ MODKEY,                       XK_KP_5,     focusstack,   { .i = -1 } },
   { MODKEY,                       XK_KP_Page_Down,  togglelayout,   {.v = &layouts[5]} },
   { MODKEY,                       XK_F12,      togglefullscreen, {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY,                       XK_Escape, spawn,          {.v = oblogout} },
   { MODKEY|ShiftMask,             XK_q,      restart,         {0} }
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        nextlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        prevlayout,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
   { ClkWinTitle,          0,              Button1,        focusonclick,   {0} },
   { ClkWinTitle,          0,              Button3,        closeonclick,   {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         ALTKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         ALTKEY,         Button2,        zoom,           {0} },
 	{ ClkClientWin,         MODKEY,         Button2,        zoom,           {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            ALTKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            ALTKEY,         Button3,        toggletag,      {0} },
};

