/* config.h */

/* appearance */
static const char font[] = "erusfont 7";

/*   border,   foreground ,background */
static const char colors[MAXCOLORS][ColLast][8] = {
   { "#010101", "#B7CE42", "#1C1C1C" }, // 0 = Normal tag
   { "#212121", "#FEA63C", "#D81860" }, // 1 = Selected tag
   { "#212121", "#66AABB", "#D81860" }, // 2 = Urgent tag
   { "#ffffff", "#ffffff", "#414141" }, // 3 = Unselected tag with windows
   { "#ffffff", "#FEA63C", "#1C1C1C" }, // 4 = Layout
   { "#212121", "#FEA63C", "#D81860" }, // 5 = Selected window
   { "#ffffff", "#D81860", "#414141" }, // 6 = Unselected window
   { "#ffffff", "#cc3300", "#dddddd" }, // 7 = Window pager text
   { "#cacaca", "#cacaca", "#414141" }, // 8 = Status bar
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
static Edge edges[] = {
   /* X   Y   W   H */
   {  0,  0,  0, 0 }, // 1
   {  0,  0,  0, 0 }, // 2
};

/* window area margins */
static Edge margins[] = {
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
   { "Thunar",   NULL,       NULL,       0,            FLOAT,         -1 },
   { "File-roller",  NULL,   NULL,       0,            FLOAT,         -1 },
   { "URxvt",    "URxvtq",   NULL,       0,            URXVTQ,         0 },
   { "Oblogout", NULL,       NULL,       0,            URXVTQ,         0 },
   { "MaCoPiX",  NULL,       NULL,       0,            WIDGET,         1 },
   { "Kupfer.py",NULL,       NULL,       0,            WIDGET,        -1 },
   { "dzen",     "dzen2",    NULL,       0,            CONKY,         -1 },
   { "Conky",    NULL,       NULL,       0,            CONKY,          1 },
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

/* PATHS */
#define FILEMANAGER     "thunar"
#define HOME            "/home/jari"
#define GAMES           "/media/Storage/Pelit"
#define EMUS            "/media/Storage/Emulaattorit"
#define ICONS           HOME"/.icons/dwm"
#define THDIR           GAMES"/Touhou"

/* layouts */
static const Layout layouts[]  = {
    /* icon (optional),  symbol     arrange function */
    { ICONS"/tile.xbm",    "TI",      tile },
    { ICONS"/bhoriz.xbm",  "BH",      bstackhoriz },
    { ICONS"/grid.xbm",    "GR" ,     grid },
    { ICONS"/bstack.xbm",  "BS" ,     bstack },
    { ICONS"/float.xbm",   "FL",      NULL },
    { ICONS"/monocle.xbm", "M",       monocle },
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

/* commands */
static const char *dmenucmd[]    = { "dmenu_run" , "-p" , "Run:" , "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *termcmd[]     = { "urxvt",            NULL };
static const char *dvolminus[]   = { "dvol", "-d", "1",  NULL };
static const char *dvolplus[]    = { "dvol", "-i", "1",  NULL };
static const char *dvolmute[]    = { "dvol", "-t",       NULL };
static const char *kupfer[]      = { "kupfer",           NULL };
static const char *oblogout[]    = { "oblogout",         NULL };
static const char *prnt[]        = { "scrot",            NULL };
static const char *opera[]       = { "opera",            NULL };
static const char *nitrogen[]    = { "nitrogen",         NULL };
static const char *urxvtq[]      = { "URXVTQ",           NULL };
static const char *irc[]         = { "IRC",              NULL };
static const char *msn[]         = { "MSN",              NULL };
static const char *torrent[]     = { "TORRENT",          NULL };
static const char *rss[]         = { "RSS",              NULL };
static const char *comix[]       = { "comix",            NULL };
static const char *deadbeef[]    = { "deadbeef",         NULL };
static const char *mame[]        = { "sdlmame",          NULL };
static const char *gvbam[]       = { "gvbam",            NULL };

/* menus */
#define MENUEND { NULL, NULL, NULL, {0} }
#define MENUSEP(x) { x, NULL, NULL, {0} }
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
   MENUSEP("-----------------------------------"),
   { "Doujin                            +",  NULL, spawn, FM(THDIR"/Doujin") },
   MENUEND,
};

static const menuCtx internetMenu[] = {
   { "Opera   ",  NULL, spawn, {.v = opera } },
   MENUSEP("--------"),
   { "rTorrent",  NULL, spawn, {.v = torrent } },
   MENUSEP("--------"),
   { "IRC     ",  NULL, spawn, {.v = irc } },
   { "MSN     ",  NULL, spawn, {.v = msn   } },
   MENUSEP("--------"),
   { "RSS     ",  NULL, spawn, {.v = rss } },
   MENUEND,
};

static const menuCtx gameMenu[] = {
   { "Touhou                >", &touhouMenu[0], NULL, {0} },
   { "Eroge                 +", NULL, spawn,
   FM("/media/Storage/Bishoujo Pelit") },
   MENUSEP("-----------------------"),
   { "Cave Story             ", NULL, spawn,
   pikakuvake(GAMES"/CaveStory/doukutsu") },
   { "Last Remnant           ", NULL, spawn,
   pikakuvake(HOME"/.wine/drive_c/Program Files/The Last Remnant/Binaries/TLR.exe") },
   { "ALLTYNEX Second        ", NULL, spawn,
   pikakuvake(GAMES"/ALLTYNEX Second/alltynex2nd.exe") },
   { "RefRain                ", NULL, spawn,
   pikakuvake(GAMES"/RefRain/runGame.sh") },
   { "Edens Aegis            ", NULL, spawn,
   pikakuvake(GAMES"/Edens Aegis/EdensAegis.run") },
   MENUSEP("-----------------------"),
   { "Grand Fantasia         ", NULL, spawn,
   pikakuvake(HOME"/.wine/drive_c/AeriaGames/GrandFantasia/runGame.sh") },
   { "Spiral Knights         ", NULL, spawn,
   pikakuvake(HOME"/spiral/spiral") },
   MENUSEP("-----------------------"),
   { "Ys The Ark of Napishtim", NULL, spawn,
   pikakuvake(GAMES"/Ys The Ark of Napishtim/ys6_win_dx9.exe") },
   { "Ys The Oath in Felghana", NULL, spawn,
   pikakuvake(GAMES"/Ys The Oath in Felghana/ysf_win_dx9.exe") },
   { "Ys Origins             ", NULL, spawn,
   pikakuvake(GAMES"/Ys Origins/YSO_WIN.exe") },
   MENUSEP("-----------------------"),
   { "Sora no Kiseki         ", NULL, spawn,
   pikakuvake(GAMES"/Eiyuu Densetsu - Sora no Kiseki/ED6_WIN.run") },
   { "Sora no Kiseki SC      ", NULL, spawn,
   pikakuvake(GAMES"/Eiyuu Densetsu - Sora no Kiseki SC/ED6_WIN2.run") },
   { "Sora no Kiseki TC      ", NULL, spawn,
   pikakuvake(GAMES"/Eiyuu Densetsu - Sora no Kiseki TC/ED6_WIN3.run") },
   MENUSEP("-----------------------"),
   { "MAME                   ", NULL, spawn, {.v = mame } },
   { "NO$GBA                 ", NULL, spawn,
   pikakuvake(EMUS"/NoGBA/NO$GBA.exe") },
   { "VBA-M                  ", NULL, spawn, {.v = gvbam } },
   MENUSEP("-----------------------"),
   { "Steam                  ", NULL, spawn,
   pikakuvake(HOME"/.wine/drive_c/Program Files/Steam/Steam.exe") },
   MENUEND,
};

static const menuCtx archMenu[] = {
   { "Nitrogen", NULL, spawn, {.v = nitrogen} },
   MENUSEP("--------"),
   { "Exit    ", NULL, spawn, {.v = oblogout} },
   MENUEND,
};

static const menuCtx rootMenu[] = {
   { "Music        ", NULL,  spawn, {.v = deadbeef } },
   { "Manga        ", NULL,  spawn, {.v = comix } },
   MENUSEP("-------------"),
   { "Internet    >", &internetMenu[0],   NULL, {0} },
   { "Games       >", &gameMenu[0],       NULL, {0} },
   MENUSEP("-------------"),
   { "ArchLinux   >", &archMenu[0],       NULL, {0} },
   MENUEND,
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
   { ALTKEY,                       XK_F2,             spawn,            {.v = kupfer} },
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

