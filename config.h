/* config.h */

#define FONT_SIZE   "7"
#ifdef XFT
#  define FONT_NAME "Erusfont"
   static const char font[] = FONT_NAME" "FONT_SIZE;
#else
#  define FONT_NAME "terminus-medium-r"
   static const char font[] = "-*-"FONT_NAME"-*-*-"FONT_SIZE"-*-*-*-*-*-*-*";
#endif

/*   border,   foreground ,background */
static const char colors[MAXCOLORS][ColLast][8] = {
   { "#212121", "#9d9d9d", "#161616" }, //  0 = Normal tag
   { "#ff950e", "#44ddff", "#161616" }, //  1 = Selected tag
   { "#212121", "#04c656", "#161616" }, //  2 = Urgent tag
   { "#212121", "#9d9d9d", "#161616" }, //  3 = Unselected tag with windows
   { "#212121", "#FEA63C", "#161616" }, //  4 = Layout
   { "#ff950e", "#9d9d9d", "#161616" }, //  5 = Selected window
   { "#212121", "#444444", "#161616" }, //  6 = Unselected window
   { "#212121", "#444444", "#444444" }, //  7 = Window pager seperator
   { "#212121", "#CACACA", "#161616" }, //  8 = Status bar
   { "#212121", "#FFFFFF", "#1793D1" }, //  9 = Selected menu
   { "#212121", "#CFCFCF", "#161616" }, // 10 = Unselected menu
   { "#212121", "#1793D1", "#161616" }, // 11 = Seperator menu
};

static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool clicktofocus      = True;     /* Click to focus windows */
static const Bool autofocusmonitor  = True;     /* Auto focus monitors */
static const Bool alwaysdrawstatus  = False;    /* Draw status to both monitors? */
static const Bool inversestatus     = False;    /* Draw status on inactive monitor */

static const Bool systray_enable = True;
static const int systray_spacing = 2;
static const int status_height   = 0;

/* Which monitor systray appears */
#define PRIMARY_MONITOR 0

/* NOTE: This disables inversestatus && alwaysdrawstatus.
 * Comment or remove this define to not use it */
#define STATUS_MONITOR  1

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
   {  0,  0,  0, 15 }, // 1 NOTE: This adds the bottom bar cap
   {  0,  0,  0,  0 }, // 2 NOTE: Second monitor has no bar
};

/* bar edges */
static Edge dwmbar[] = {
   /* X   Y   W   H */
   {  0,  0,-230, 0 },
   {  0,  0,  0,  0 },
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
/*             floating,widget,  below.   above,   zombie,  sticky,  border */
#define NORMAL False,   False,   False,   False,   False,   False,   True
#define FLOAT  True,    False,   False,   False,   False,   False,   True
#define WIDGET True,    True,    False,   True,    False,   True,    False
#define CONKY  True,    True,    True,    False,   True,    True,    False
#define URXVTQ True,    False,   False,   True,    False,   True,    False
#define DOCK   True,    True,    False,   True,    False,   True,    False
#define PANEL  True,    True,    True,    False,   False,   True,    False
#define TERM   False,   False,   False,   False,   False,   False,   True

static const Rule rules[] = {
   /* class      instance    title       tags mask     type           monitor */
   { "File-roller",  NULL,   NULL,         0,            FLOAT,         -1 },
   { "Oblogout", NULL,       NULL,         0,            URXVTQ,         0 },
   { "MaCoPiX",  NULL,       NULL,         0,            WIDGET,         1 },
   { "dzen",     "dzen2",    NULL,         0,            CONKY,          0 },
   { "Conky",    NULL,       NULL,         0,            CONKY,          1 },
   { "URxvt",    NULL,       NULL,         0,            TERM,          -1 },
   { "URxvt",    "URxvtq",   NULL,         0,            URXVTQ,         0 },
   { "URxvt",    NULL,       "rTorrent",   1 << 2,       TERM,           1 },
   { "URxvt",    NULL,       "SnowNews",   1 << 1,       TERM,           1 },
   { "URxvt",    "IRC",      NULL,         1 << 0,       TERM,           1 },
   { "dwb",      NULL,       NULL,         0,            TERM,          -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

/* num of masters */
static const int nmaster = 2;

/* PATHS */
#define FILEMANAGER     "spacefm"
#define HOME            "/home/jari"
#define GAMES           "/media/Storage/Pelit"
#define EMUS            "/media/Storage/Emulaattorit"
#define ICONS           HOME"/.icons/dwm"
#define THDIR           GAMES"/Touhou"

/* layouts */
static const Layout layouts[]  = {
    /* icon (optional),  symbol     arrange function */
    { ICONS"/tile.xbm",    "TI",      tile },         /* 0 */
    { ICONS"/bhoriz.xbm",  "BH",      bstackhoriz },  /* 1 */
    { ICONS"/grid.xbm",    "GR" ,     grid },         /* 2 */
    { ICONS"/bstack.xbm",  "BS" ,     bstack },       /* 3 */
    { ICONS"/float.xbm",   "FL",      NULL },         /* 4 */
    { ICONS"/monocle.xbm", "M",       monocle },      /* 5 */
    { NULL, NULL,  NULL },
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
#define THCMD(exe)      { .v = (const char*[]){ "pikakuvake", THDIR"/"exe, NULL } }
#define FM(path)        { .v = (const char*[]){ FILEMANAGER, path, NULL } }

#define SHCMD(cmd)      { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define pikakuvake(cmd) { .v = (const char*[]){ "pikakuvake", cmd, NULL } }
#define STEAM  { .v = (const char*[]){ "steam", NULL } }
#define DESURA { .v = (const char*[]){ "desura", NULL } }

/* commands */
#ifdef XFT
static const char *dmenucmd[]    = { "dmenu_run" , "-p" , "dwm" , "-fn", FONT_NAME":"FONT_SIZE, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
#else
static const char *dmenucmd[]    = { "dmenu_run" , "-p" , "dwm" , "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
#endif
static const char *termcmd[]     = { "urxvt",            NULL };
static const char *dvolminus[]   = { "dvol", "-d", "1",  NULL };
static const char *dvolplus[]    = { "dvol", "-i", "1",  NULL };
static const char *dvolmute[]    = { "dvol", "-t",       NULL };
static const char *oblogout[]    = { "oblogout",         NULL };
static const char *prnt[]        = { "scrot",            NULL };
static const char *dwb[]         = { "dwb",              NULL };
static const char *nitrogen[]    = { "nitrogen",         NULL };
static const char *urxvtq[]      = { "URXVTQ",           NULL };
static const char *irc[]         = { "IRC",              NULL };
static const char *torrent[]     = { "TORRENT",          NULL };
static const char *rss[]         = { "RSS",              NULL };
static const char *comix[]       = { "comix",            NULL };
static const char *deadbeef[]    = { "deadbeef",         NULL };
static const char *mame[]        = { "sdlmame",          NULL };
static const char *gvbam[]       = { "gvbam",            NULL };

/* menus */
#define MENUEND { NULL, NULL, NULL, {0} }
#define MENUSEP { "", NULL, NULL, {0} }
static const menuCtx touhouMenu[] = {
   { "TH06 Embodiment of Scarlet Devil   ",  NULL, spawn, THCMD("TH06/th06e.exe") },
   { "TH07 Perfect Cherry Blossom        ",  NULL, spawn, THCMD("TH07/th07e.exe") },
   { "TH07.5 Immaterial and Missing Power",  NULL, spawn, THCMD("TH07.5/th075e.exe") },
   { "TH08 Imperishable Night            ",  NULL, spawn, THCMD("TH08/th08.exe") },
   { "TH09 Phantasmagoria of Flower View ",  NULL, spawn, THCMD("TH09/th09e.exe") },
   { "TH09.5 Shoot the Bullet            ",  NULL, spawn, THCMD("TH09.5/th095.exe") },
   { "TH10 Mountain of Faith             ",  NULL, spawn, THCMD("TH10/th10e.exe") },
   { "TH10.5 Scarlet Weather Rhapsody    ",  NULL, spawn, THCMD("TH10.5/th105e.exe") },
   { "TH11 Subterranean Animism          ",  NULL, spawn, THCMD("TH11/th11e.exe") },
   { "TH12 Undefined Fantastic Object    ",  NULL, spawn, THCMD("TH12/th12e.exe") },
   { "TH12.3 Touhou Hisoutensoku         ",  NULL, spawn, THCMD("TH12.3/th123e.exe") },
   { "TH12.5 Double Spoiler              ",  NULL, spawn, THCMD("TH12.5/th125e.exe") },
   { "TH12.8 Fairy Wars                  ",  NULL, spawn, THCMD("TH12.8/th128e.exe") },
   { "TH13 Ten Desires                   ",  NULL, spawn, THCMD("TH13/th13.exe") },
   MENUSEP,
   { "Doujin                            +",  NULL, spawn, FM(THDIR"/Doujin") },
   MENUEND,
};

static const menuCtx internetMenu[] = {
   { "dwb",          NULL, spawn, {.v = dwb } },
   MENUSEP,
   { "rTorrent",     NULL, spawn, {.v = torrent } },
   MENUSEP,
   { "IRC",          NULL, spawn, {.v = irc } },
   MENUSEP,
   { "RSS",          NULL, spawn, {.v = rss } },
   MENUEND,
};

static const menuCtx gameMenu[] = {
   { "Touhou                >", &touhouMenu[0], NULL, {0} },
   { "Eroge                 +", NULL, spawn,
   FM("/media/Storage/Bishoujo Pelit") },
   MENUSEP,
   { "The Last Remnant       ", NULL, spawn,
   pikakuvake(GAMES"/The Last Remnant/Binaries/TLR.exe") },
   { "TES V : Skyrim         ", NULL, spawn,
   pikakuvake(GAMES"/The Elder Scrolls V Skyrim/skse_loader.exe") },
   { "ALLTYNEX Second        ", NULL, spawn,
   pikakuvake(GAMES"/ALLTYNEX Second/alltynex2nd.exe") },
   { "Edens Aegis            ", NULL, spawn,
   pikakuvake(GAMES"/Edens Aegis/EdensAegis.run") },
   MENUSEP,
   { "Ys The Ark of Napishtim", NULL, spawn,
   pikakuvake(GAMES"/Ys The Ark of Napishtim/ys6_win_dx9.exe") },
   { "Ys The Oath in Felghana", NULL, spawn,
   pikakuvake(GAMES"/Ys The Oath in Felghana/ysf_win_dx9.exe") },
   { "Ys Origin              ", NULL, spawn,
   pikakuvake(GAMES"/Ys Origin/YSO_WIN.run") },
   MENUSEP,
   { "Sora no Kiseki         ", NULL, spawn,
   pikakuvake(GAMES"/Eiyuu Densetsu - Sora no Kiseki/ED6_WIN.run") },
   { "Sora no Kiseki SC      ", NULL, spawn,
   pikakuvake(GAMES"/Eiyuu Densetsu - Sora no Kiseki SC/ED6_WIN2.run") },
   { "Sora no Kiseki TC      ", NULL, spawn,
   pikakuvake(GAMES"/Eiyuu Densetsu - Sora no Kiseki TC/ED6_WIN3.run") },
   { "Zero no Kiseki         ", NULL, spawn,
   pikakuvake(GAMES"/Eiyuu Densetsu - Zero no Kiseki/ED_ZERO.run") },
   MENUSEP,
   { "MAME                   ", NULL, spawn, {.v = mame } },
   { "NO$GBA                 ", NULL, spawn,
   pikakuvake(EMUS"/NoGBA/NO$GBA.exe") },
   MENUSEP,
   { "Steam                  ", NULL, spawn, STEAM  },
   { "Desura                 ", NULL, spawn, DESURA },
   MENUEND,
};

static const menuCtx archMenu[] = {
   { "Nitrogen", NULL, spawn, {.v = nitrogen} },
   MENUSEP,
   { "Exit    ", NULL, spawn, {.v = oblogout} },
   MENUEND,
};

static const menuCtx rootMenu[] = {
   { "Music        ", NULL,  spawn, {.v = deadbeef } },
   { "Manga        ", NULL,  spawn, {.v = comix } },
   MENUSEP,
   { "Internet    >", &internetMenu[0],   NULL, {0} },
   { "Games       >", &gameMenu[0],       NULL, {0} },
   MENUSEP,
   { "ArchLinux   >", &archMenu[0],       NULL, {0} },
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
   { 0,                            0x1008ff11,        spawn,            {.v = dvolminus } },
   { 0,                            0x1008ff13,        spawn,            {.v = dvolplus  } },
   { 0,                            0x1008ff12,        spawn,            {.v = dvolmute  } },
   { 0,                            0x1008ff30,        spawn,            {.v = termcmd   } },
   { 0,                            XK_section,        spawn,            {.v = urxvtq } },
   { 0,                            XK_Print,          spawn,            {.v = prnt } },
   { ALTKEY,                       XK_Print,          spawn,            SHCMD("import $HOME/dwm-$(date +'%H:%M-%d-%m-%Y').png") },
   { MODKEY,                       XK_p,              spawn,            {.v = dmenucmd } },
   { MODKEY|ShiftMask,             XK_Return,         spawn,            {.v = termcmd } },
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
   { MODKEY,                       XK_comma,          focusmonitor,     {.i = -1 } },
   { MODKEY,                       XK_period,         focusmonitor,     {.i = +1 } },
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
   { MODKEY,                       XK_Escape,         spawn,            {.v = oblogout} },
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
   { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
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

