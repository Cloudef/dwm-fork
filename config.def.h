/* config.def
 * Default configuration */

#define FONT_SIZE "7"
#ifdef XFT
#  define FONT_NAME "terminus"
   static const char font[] = FONT_NAME" "FONT_SIZE;
#else
#  define FONT_NAME "terminus-medium-r"
   static const char font[] = "-*-"FONT_NAME"-*-*-"FONT_SIZE"-*-*-*-*-*-*-*";
#endif

/*   border,   foreground ,background */
static const char colors[MAXCOLORS][ColLast][8] = {
   { "#212121", "#9d9d9d", "#161616" }, //  0 = Normal tag
   { "#212121", "#44ddff", "#161616" }, //  1 = Selected tag
   { "#212121", "#04c656", "#161616" }, //  2 = Urgent tag
   { "#212121", "#9d9d9d", "#161616" }, //  3 = Unselected tag with windows
   { "#212121", "#FEA63C", "#161616" }, //  4 = Layout
   { "#212121", "#9d9d9d", "#161616" }, //  5 = Selected window
   { "#212121", "#444444", "#161616" }, //  6 = Unselected window
   { "#212121", "#444444", "#444444" }, //  7 = Window pager seperator
   { "#212121", "#CACACA", "#161616" }, //  8 = Status bar
   { "#212121", "#FFFFFF", "#1793D1" }, //  9 = Selected menu
   { "#212121", "#CFCFCF", "#161616" }, // 10 = Unselected menu
   { "#212121", "#1793D1", "#161616" }, // 11 = Seperator menu
};

static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool clicktofocus      = True;     /* Click to focus windows */
static const Bool autofocusmonitor  = True;     /* Auto focus monitors */
static const Bool alwaysdrawstatus  = True;     /* Draw status to both monitors? */
static const Bool inversestatus     = False;    /* Draw status on inactive monitor */

static const Bool systray_enable = True;
static const int systray_spacing = 2;
static const int status_height   = 0;

/* which monitor systray appears */
#define PRIMARY_MONITOR 0

/* NOTE: This disables inversestatus && alwaysdrawstatus.
 * Comment or remove this define to not use it */
/* #define STATUS_MONITOR 0 */

/* display edges, similar to margins expect
 * everything gets affected */
static Edge edges[] = {
   /* X   Y   W   H */
   {  0,  0,  0, 0 }, // 1
   {  0,  0,  0, 0 }, // 2
};

/* window area margins */
static Edge margins[] = {
   /* X   Y   W   H */
   {  0,  0,  0,  0 }, // 1
   {  0,  0,  0,  0 }, // 2
};

/* bar edges */
static Edge dwmbar[] = {
   /* X   Y   W   H */
   {  0,  0,  0, 0 },
   {  0,  0,  0,  0 },
};

/* tagging */
static const char *tags[] = { "D", "W", "M" };
Bool autohide             = False;

/* floating = floating window
 * widget   = window without border and statusbar
 * below    = always below
 * above    = always above
 * zombie   = do not take input
 * sticky   = stay on all tags */

/*             floating,widget,  below.   above,   zombie,  sticky */
#define NORMAL False,   False,   False,   False,   False,   False
#define FLOAT  True,    False,   False,   False,   False,   False
#define WIDGET True,    True,    False,   True,    False,   True
#define DOCK   True,    True,    False,   True,    False,   True

static const Rule rules[] = {
   /* class      instance    title       tags mask     type           monitor */
   { "Gimp",     NULL,       NULL,       0,            FLOAT,         -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

/* num of masters */
static const int nmaster = 2;

/* layouts */
static const Layout layouts[]  = {
    /* icon, symbol, arrange function */
    { NULL, "TI",    tile },
    { NULL, "BH",    bstackhoriz },
    { NULL, "GR" ,   grid },
    { NULL, "BS" ,   bstack },
    { NULL, "FL",    NULL },
    { NULL, "M",     monocle },
    { NULL, NULL, NULL, },
};

/* key definitions */
#define MODKEY  Mod4Mask
#define CTRLKEY ControlMask
#define ALTKEY  Mod1Mask
#define TAGKEYS(KEY,TAG) \
        { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
        { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper defines */
#define SHCMD(cmd)      { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
#ifdef XFT
/* needs dmenu-xft */
static const char *dmenucmd[]    = { "dmenu_run" , "-p" , "dwm" , "-fn", FONT_NAME":"FONT_SIZE, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
#else
static const char *dmenucmd[]    = { "dmenu_run" , "-p" , "dwm" , "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
#endif

/* menus */
#define MENUEND { NULL, NULL, NULL, {0} }
#define MENUSEP {   "", NULL, NULL, {0} }

/* title, submenu, function, argument */
static const menuCtx rootMenu[] = {
   MENUSEP,
   { "EMPTY", NULL,  NULL, {0} },
   MENUSEP,
   MENUEND,
};

/* menu key bindings
 * only grabbed when menu is alive. */
static Key menu_keys[] = {
   { 0, XK_Up,       menu_up,       {0} },
   { 0, XK_Down,     menu_down,     {0} },
   { 0, XK_Right,    menu_next,     {0} },
   { 0, XK_Left,     menu_prev,     {0} },
   { 0, XK_Return,   menu_accept,   {0} },
   { 0, XK_Escape,   togglemenu,    {0} }
};

/* keys */
static Key keys[] = {
   /* modifier                     key                function          argument */
   { MODKEY,                       XK_p,              spawn,            {.v = dmenucmd } },
   { MODKEY,                       XK_b,              togglebar,        {.i = -1} },
   { MODKEY,                       XK_j,              focusstack,       {.i = +1 } },
   { MODKEY,                       XK_k,              focusstack,       {.i = -1 } },
   { MODKEY,                       XK_h,              setmfact,         {.f = -0.05} },
   { MODKEY,                       XK_l,              setmfact,         {.f = +0.05} },
   { MODKEY,                       XK_Return,         zoom,             {0} },
   { MODKEY,                       XK_q,              killclient,       {0} },
   { ALTKEY,                       XK_s,              resizemouse,      {0} },
   { MODKEY,                       XK_s,              togglesticky,     {0} },
   { MODKEY,                       XK_0,              view,             {.ui = ~0 } },
   { MODKEY|ShiftMask,             XK_0,              tag,              {.ui = ~0 } },
   { MODKEY,                       XK_comma,          focusmon,         {.i = -1 } },
   { MODKEY,                       XK_period,         focusmon,         {.i = +1 } },
   { MODKEY|ShiftMask,             XK_comma,          tagmon,           {.i = -1 } },
   { MODKEY|ShiftMask,             XK_period,         tagmon,           {.i = +1 } },
   { MODKEY,                       XK_KP_End,         nextlayout,       {0} },
   { MODKEY,                       XK_KP_Down,        prevlayout,       {0} },
   { MODKEY,                       XK_KP_Insert,      cyclezoom,        {0} },
   { MODKEY,                       XK_KP_Delete,      togglefloating,   {0} },
   { MODKEY,                       XK_KP_Home,        setmfact,         {.f = -0.05} },
   { MODKEY,                       XK_KP_Up,          setmfact,         {.f = +0.05} },
   { MODKEY,                       XK_KP_Left,        focusstack,       {.i = -1} },
   { MODKEY,                       XK_KP_Right,       focusstack,       {.i = +1} },
   { MODKEY,                       XK_KP_Page_Down,   togglelayout,     {.v = &layouts[5]} },
   { MODKEY,                       XK_F12,            togglefullscreen, {0} },
   { CTRLKEY,                      XK_space,          togglemenu,       {0} },
   TAGKEYS(                        XK_1,                      0)
   TAGKEYS(                        XK_2,                      1)
   TAGKEYS(                        XK_3,                      2)
   TAGKEYS(                        XK_4,                      3)
   TAGKEYS(                        XK_5,                      4)
   TAGKEYS(                        XK_6,                      5)
   TAGKEYS(                        XK_7,                      6)
   TAGKEYS(                        XK_8,                      7)
   TAGKEYS(                        XK_9,                      8)
   { MODKEY|ShiftMask,             XK_q,              restart,          {0} }
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
   /* click                event mask      button          function        argument */
   { ClkLtSymbol,          0,              Button1,        nextlayout,     {0} },
   { ClkLtSymbol,          0,              Button3,        prevlayout,     {0} },
   { ClkWinTitle,          0,              Button2,        zoom,           {0} },
   { ClkWinTitle,          0,              Button1,        focusonclick,   {0} },
   { ClkWinTitle,          0,              Button3,        closeonclick,   {0} },
   { ClkStatusText,        0,              Button3,        togglemenu,     {0} },
   { ClkClientWin,         ALTKEY,         Button1,        movemouse,      {0} },
   { ClkClientWin,         ALTKEY,         Button2,        zoom,           {0} },
   { ClkClientWin,         MODKEY,         Button2,        zoom,           {0} },
   { ClkTagBar,            0,              Button1,        view,           {0} },
   { ClkTagBar,            0,              Button3,        toggleview,     {0} },
   { ClkTagBar,            ALTKEY,         Button1,        tag,            {0} },
   { ClkTagBar,            ALTKEY,         Button3,        toggletag,      {0} },
   { ClkRootWin,           0,              Button3,        togglemenu,     {0} },
};

