AC_INIT([enigma2-oe-alliance-plugins],[1.0])
AM_INIT_AUTOMAKE([dist-bzip2 foreign no-define tar-pax])
AC_CONFIG_HEADERS([enigma2-plugins-config.h])

# Silent rules are available since 1.11, but older versions
# are still in use. So don't use them unconditionally.
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_USE_SYSTEM_EXTENSIONS
AC_SYS_LARGEFILE

AC_PROG_CC
AC_PROG_CXX
m4_ifdef([LT_INIT], [LT_INIT], [AC_PROG_LIBTOOL])
AC_CONFIG_MACRO_DIR([m4])

AC_CHECK_HEADERS([dbox/fp.h dbox/lcd-ks0713.h])

AC_PATH_PROG(MSGFMT, msgfmt, AC_MSG_ERROR(Could not find msgfmt))

AM_PATH_PYTHON
AX_PYTHON_DEVEL
AX_PTHREAD

AC_ARG_WITH(boxtype,
	[  --with-boxtype=NAME box type [[none,dm7025,dm800...]]],
	[BOXTYPE="$withval"],[BOXTYPE="dm800"])
AC_SUBST(BOXTYPE)
AC_DEFINE_UNQUOTED(BOXTYPE,"$BOXTYPE",[box type])

AC_ARG_WITH(oever,
	[  --with-oever=NAME oe name [[OE-A1,OE-A2,...]]],
	[OE_VER="$withval"],[OE_VER="OE-Alliance 2.0"])
AC_SUBST(OE_VER)
AC_DEFINE_UNQUOTED(OE_VER,"$OE_VER",[oe name])

AC_ARG_WITH(distro,
	[  --with-distro=NAME distro name [[openvix,openaaf,...]]],
	[DISTRO="$withval"],[DISTRO="egami"])
AC_SUBST(DISTRO)
AC_DEFINE_UNQUOTED(DISTRO,"$DISTRO",[distro name])

AC_ARG_WITH(machinebrand,
	[  --with-machinebrand=NAME brand name [[Vu,Xtrend,...]]],
	[MACHINE_BRAND="$withval"],[MACHINE_BRAND="Vu+"])
AC_SUBST(MACHINE_BRAND)
AC_DEFINE_UNQUOTED(MACHINE_BRAND,"$MACHINE_BRAND",[machine brand])

AC_ARG_WITH(machinename,
	[  --with-machinename=NAME machine name [[Solo,Ultimo,...]]],
	[MACHINE_NAME="$withval"],[MACHINE_NAME="Ultimo"])
AC_SUBST(MACHINE_NAME)
AC_DEFINE_UNQUOTED(MACHINE_NAME,"$MACHINE_NAME",[machine name])

AC_ARG_WITH(machineoem,
	[  --with-machineoem=NAME machine oem [[DAGS,DMM,...]]],
	[MACHINE_OEM="$withval"],[MACHINE_OEM="DAGS"])
AC_SUBST(MACHINE_OEM)
AC_DEFINE_UNQUOTED(MACHINE_OEM,"$MACHINE_OEM",[machine oem])

AC_ARG_WITH(imageversion,
	[  --with-imageversion=NAME version number [[3.0]]],
	[IMAGEVERSION="$withval"],[IMAGEVERSION=""])
AC_SUBST(IMAGEVERSION)
AC_DEFINE_UNQUOTED(IMAGEVERSION,"$IMAGEVERSION",[version number])

AC_ARG_WITH(imagebuild,
	[  --with-imagebuild=NAME build number [[628]]],
	[IMAGEBUILD="$withval"],[IMAGEBUILD=""])
AC_SUBST(IMAGEBUILD)
AC_DEFINE_UNQUOTED(IMAGEBUILD,"$IMAGEBUILD",[build number])

AC_ARG_WITH(driverdate,
	[  --with-driverdate=NAME driver date [[628]]],
	[DRIVERDATE="$withval"],[DRIVERDATE=""])
AC_SUBST(DRIVERDATE)
AC_DEFINE_UNQUOTED(DRIVERDATE,"$DRIVERDATE",[driver date])


AC_ARG_WITH(debug,
	AS_HELP_STRING([--without-debug],[disable debugging code]),
	[with_debug="$withval"],[with_debug="yes"])
if test "$with_debug" = "yes"; then
	DEBUG_CFLAGS="-ggdb3"
	AC_DEFINE([DEBUG],[1],[Define to 1 to enable debugging code])
fi
AC_SUBST(DEBUG_CFLAGS)

AC_ARG_WITH(po,
	AS_HELP_STRING([--with-po],[enable updating of po files]),
	[with_po="$withval"],[with_po="no"])
if test "$with_po" = "yes"; then
	AC_PATH_PROG(MSGINIT, msginit)
	AC_PATH_PROG(MSGMERGE, msgmerge)
	AC_PATH_PROG(MSGUNIQ, msguniq)
	AC_PATH_PROG(XGETTEXT, xgettext)
	if test -z "$MSGINIT" -o -z "$MSGMERGE" -o -z "$MSGUNIQ" -o -z "$XGETTEXT"; then
		AC_MSG_ERROR([Could not find required gettext tools])
	fi
fi
AM_CONDITIONAL(UPDATE_PO, test "$with_po" = "yes")

AM_CONDITIONAL(AZBOX, test `echo "$BOXTYPE" | cut -b 1-5` == "azbox")
AM_CONDITIONAL(CUBE, test `echo "$BOXTYPE" | cut -b 1-4` == "cube")
AM_CONDITIONAL(DREAMBOX, test `echo "$BOXTYPE" | cut -b 1-2` == "dm")
AM_CONDITIONAL(TECHNOMATE, test `echo "$BOXTYPE" | cut -b 1-2` == "tm")
AM_CONDITIONAL(IQON, test `echo "$BOXTYPE" | cut -b 1-4` == "iqon")
AM_CONDITIONAL(VUPLUS, test `echo "$MACHINE_OEM"` == "vuplus")
AM_CONDITIONAL(XTREND, test `echo "$MACHINE_OEM"` == "xtrend")
AM_CONDITIONAL(DAGS, test `echo "$MACHINE_OEM" | cut -b 1-4` == "dags")
AM_CONDITIONAL(GIGABLUE, test `echo "$MACHINE_OEM"` == "gigablue")
AM_CONDITIONAL(ODIN, test `echo "$MACHINE_OEM" | cut -b 1-4` == "odin")
AM_CONDITIONAL(INI, test `echo "$MACHINE_OEM" | cut -b 1-3` == "ini")
AM_CONDITIONAL(SEZAM, test `echo "$BOXTYPE" | cut -b 1-5` == "sezam")
AM_CONDITIONAL(XPEED, test `echo "$BOXTYPE" | cut -b 1-5` == "xpeed")
AM_CONDITIONAL(VENTON, test `echo "$BOXTYPE" | cut -b 1-6` == "venton")
AM_CONDITIONAL(MIRACLEBOX, test `echo "$BOXTYPE" | cut -b 1-2` == "mb")
AM_CONDITIONAL(EBOX, test `echo "$MACHINE_OEM" | cut -b 1-4` == "ebox")
AM_CONDITIONAL(EDISION, test `echo "$BOXTYPE" | cut -b 1-4` == "opti")
AM_CONDITIONAL(EVO, test `echo "$BOXTYPE" | cut -b 1-4` == "enfi")
AM_CONDITIONAL(JEPSSEN, test `echo "$BOXTYPE" | cut -b 1-5` == "media")
AM_CONDITIONAL(SOGNO, test `echo "$BOXTYPE" | cut -b 1-5` == "sogno")
AM_CONDITIONAL(AZBOXME, test "$BOXTYPE" == azboxme)
AM_CONDITIONAL(AZBOXMINIME, test "$BOXTYPE" == azboxminime)
AM_CONDITIONAL(AZBOXHD, test "$BOXTYPE" == azboxhd)
AM_CONDITIONAL(DM8000, test "$BOXTYPE" == dm8000)
AM_CONDITIONAL(DM7020HD, test "$BOXTYPE" == dm7020hd)
AM_CONDITIONAL(DM7020HDV2, test "$BOXTYPE" == dm7020hdv2)
AM_CONDITIONAL(DM800, test "$BOXTYPE" == dm800)
AM_CONDITIONAL(DM800HD, test "$BOXTYPE" == dm800hd)
AM_CONDITIONAL(DM800SE, test "$BOXTYPE" == dm800se)
AM_CONDITIONAL(DM800SEV2, test "$BOXTYPE" == dm800sev2)
AM_CONDITIONAL(DM500HD, test "$BOXTYPE" == dm500hd)
AM_CONDITIONAL(DM500HDV2, test "$BOXTYPE" == dm500hdv2)
AM_CONDITIONAL(E3HD, test "$MACHINE_OEM" == e3hd)
AM_CONDITIONAL(ET4X00, test "$BOXTYPE" == et4x00)
AM_CONDITIONAL(ET5X00, test "$BOXTYPE" == et5x00)
AM_CONDITIONAL(ET6X00, test "$BOXTYPE" == et6x00)
AM_CONDITIONAL(ET9X00, test "$BOXTYPE" == et9x00)
AM_CONDITIONAL(ET8000, test "$BOXTYPE" == et8000)
AM_CONDITIONAL(ET10000, test "$BOXTYPE" == et10000)
AM_CONDITIONAL(ENFINITY, test "$BOXTYPE" == enfinity)
AM_CONDITIONAL(FORCE1, test "$BOXTYPE" == force1)
AM_CONDITIONAL(GB800SOLO, test "$BOXTYPE" == gb800solo)
AM_CONDITIONAL(GB800SE, test "$BOXTYPE" == gb800se)
AM_CONDITIONAL(GB800UE, test "$BOXTYPE" == gb800ue)
AM_CONDITIONAL(GB800SEPLUS, test "$BOXTYPE" == gb800seplus)
AM_CONDITIONAL(GB800UEPLUS, test "$BOXTYPE" == gb800ueplus)
AM_CONDITIONAL(GBQUADPLUS, test "$BOXTYPE" == gbquadplus)
AM_CONDITIONAL(GBQUAD, test "$BOXTYPE" == gbquad)
AM_CONDITIONAL(INIHDE, test "$BOXTYPE" == inihde)
AM_CONDITIONAL(INIHDP, test "$BOXTYPE" == inihdp)
AM_CONDITIONAL(IQONIOS100HD, test "$BOXTYPE" == iqonios100hd)
AM_CONDITIONAL(IQONIOS200HD, test "$BOXTYPE" == iqonios200hd)
AM_CONDITIONAL(IQONIOS300HD, test "$BOXTYPE" == iqonios300hd)
AM_CONDITIONAL(IXUSSONE, test "$BOXTYPE" == ixussone)
AM_CONDITIONAL(IXUSSZERO, test "$BOXTYPE" == ixusszero)
AM_CONDITIONAL(IXUSSDUO, test "$BOXTYPE" == ixussduo)
AM_CONDITIONAL(MEDIABOX, test "$BOXTYPE" == mediabox)
AM_CONDITIONAL(MBTWIN, test "$BOXTYPE" == mbtwin)
AM_CONDITIONAL(ODINM6, test "$BOXTYPE" == odinm6)
AM_CONDITIONAL(ODINM7, test "$BOXTYPE" == odinm7)
AM_CONDITIONAL(ODINM9, test "$BOXTYPE" == odinm9)
AM_CONDITIONAL(OPTIMUSSOS1, test "$BOXTYPE" == optimussos1)
AM_CONDITIONAL(OPTIMUSSOS2, test "$BOXTYPE" == optimussos2)
AM_CONDITIONAL(SOGNO8800HD, test "$BOXTYPE" == sogno8800hd)
AM_CONDITIONAL(TMTWINOE, test "$BOXTYPE" == tmtwin)
AM_CONDITIONAL(TM2TOE, test "$BOXTYPE" == tm2t)
AM_CONDITIONAL(TMSINGLE, test "$BOXTYPE" == tmsingle)
AM_CONDITIONAL(TMNANO, test "$BOXTYPE" == tmnano)
AM_CONDITIONAL(VUUNO, test "$BOXTYPE" == vuuno)
AM_CONDITIONAL(VUULTIMO, test "$BOXTYPE" == vuultimo)
AM_CONDITIONAL(VUSOLO, test "$BOXTYPE" == vusolo)
AM_CONDITIONAL(VUDUO, test "$BOXTYPE" == vuduo)
AM_CONDITIONAL(VUSOLO2, test "$BOXTYPE" == vusolo2)
AM_CONDITIONAL(VUDUO2, test "$BOXTYPE" == vuduo2)
AM_CONDITIONAL(VENTONHDX, test "$BOXTYPE" == ventonhdx)
AM_CONDITIONAL(XP1000, test "$MACHINE_OEM" == xp1000)
AM_CONDITIONAL(SPARK, test "$BOXTYPE" == spark)
AM_CONDITIONAL(SPARK7162, test "$BOXTYPE" == spark7162)

AC_CONFIG_FILES([
Makefile

BoxBranding/Makefile
BoxBranding/lib/Makefile
BoxBranding/remotes/Makefile
BoxBranding/remotes/azboxhd/Makefile
BoxBranding/remotes/azboxme/Makefile
BoxBranding/remotes/azboxelite/Makefile
BoxBranding/remotes/cube/Makefile
BoxBranding/remotes/dmm0/Makefile
BoxBranding/remotes/dmm1/Makefile
BoxBranding/remotes/dmm2/Makefile
BoxBranding/remotes/e3hd/Makefile
BoxBranding/remotes/ebox5000/Makefile
BoxBranding/remotes/evo/Makefile
BoxBranding/remotes/et4x00/Makefile
BoxBranding/remotes/et6x00/Makefile
BoxBranding/remotes/et6500/Makefile
BoxBranding/remotes/et8000/Makefile
BoxBranding/remotes/et9500/Makefile
BoxBranding/remotes/et9x00/Makefile
BoxBranding/remotes/gb/Makefile
BoxBranding/remotes/ini0/Makefile
BoxBranding/remotes/ini1/Makefile
BoxBranding/remotes/ini2/Makefile
BoxBranding/remotes/ini3/Makefile
BoxBranding/remotes/ini4/Makefile
BoxBranding/remotes/iqon/Makefile
BoxBranding/remotes/ixussone/Makefile
BoxBranding/remotes/ixusszero/Makefile
BoxBranding/remotes/mediabox/Makefile
BoxBranding/remotes/odinm6/Makefile
BoxBranding/remotes/odinm7/Makefile
BoxBranding/remotes/odinm9/Makefile
BoxBranding/remotes/optimuss/Makefile
BoxBranding/remotes/sogno/Makefile
BoxBranding/remotes/tm/Makefile
BoxBranding/remotes/vu/Makefile
BoxBranding/remotes/vu2/Makefile
BoxBranding/remotes/vu3/Makefile
BoxBranding/remotes/xp1000/Makefile
BoxBranding/remotes/spark/Makefile


])
AC_OUTPUT
