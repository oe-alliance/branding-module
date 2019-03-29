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
	[  --with-distro=NAME distro name [[openvix,openatv,...]]],
	[DISTRO="$withval"],[DISTRO="egami"])
AC_SUBST(DISTRO)
AC_DEFINE_UNQUOTED(DISTRO,"$DISTRO",[distro name])

AC_ARG_WITH(imagetype,
	[  --with-imagetype=NAME imagetype name [[release,developer,...]]],
	[DISTRO_TYPE="$withval"],[DISTRO_TYPE="release"])
AC_SUBST(DISTRO_TYPE)
AC_DEFINE_UNQUOTED(DISTRO_TYPE,"$DISTRO_TYPE",[imagetype name])

AC_ARG_WITH(arch,
	[  --with-arch=NAME arch name [[mipsel32,sh4...]]],
	[ARCH_TYPE="$withval"],[ARCH_TYPE="mipsel32"])
AC_SUBST(ARCH_TYPE)
AC_DEFINE_UNQUOTED(ARCH_TYPE,"$ARCH_TYPE",[arch name])

AC_ARG_WITH(display-type,
	[  --with-display-type=NAME display type [[7segment,textlcd...]]],
	[DISPLAY_TYPE="$withval"],[DISPLAY_TYPE="textlcd"])
AC_SUBST(DISPLAY_TYPE)
AC_DEFINE_UNQUOTED(DISPLAY_TYPE,"$DISPLAY_TYPE",[display type])

AC_ARG_WITH(hdmi,
	[  --with-hdmi=NAME hdmi [[hdmi......]]],
	[HAVE_HDMI="$withval"],[HAVE_HDMI="true"])
AC_SUBST(HAVE_HDMI)
AC_DEFINE_UNQUOTED(HAVE_HDMI,"$HAVE_HDMI",[hdmi])

AC_ARG_WITH(yuv,
	[  --with-yuv=NAME yuv [[yuv......]]],
	[HAVE_YUV="$withval"],[HAVE_YUV="true"])
AC_SUBST(HAVE_YUV)
AC_DEFINE_UNQUOTED(HAVE_YUV,"$HAVE_YUV",[yuv])

AC_ARG_WITH(rca,
	[  --with-rca=NAME rca [[rca......]]],
	[HAVE_RCA="$withval"],[HAVE_RCA="true"])
AC_SUBST(HAVE_RCA)
AC_DEFINE_UNQUOTED(HAVE_RCA,"$HAVE_RCA",[rca])

AC_ARG_WITH(av-jack,
	[  --with-av-jack=NAME av-jack [[av-jack......]]],
	[HAVE_AV_JACK="$withval"],[HAVE_AV_JACK="true"])
AC_SUBST(HAVE_AV_JACK)
AC_DEFINE_UNQUOTED(HAVE_AV_JACK,"$HAVE_AV_JACK",[av-jack])

AC_ARG_WITH(scart,
	[  --with-scart=NAME scart [[scart......]]],
	[HAVE_SCART="$withval"],[HAVE_SCART="true"])
AC_SUBST(HAVE_SCART)
AC_DEFINE_UNQUOTED(HAVE_SCART,"$HAVE_SCART",[scart])

AC_ARG_WITH(scart-yuv,
	[  --with-scart-yuv=NAME scart-yuv [[scart-yuv......]]],
	[HAVE_SCART_YUV="$withval"],[HAVE_SCART_YUV="true"])
AC_SUBST(HAVE_SCART_YUV)
AC_DEFINE_UNQUOTED(HAVE_SCART_YUV,"$HAVE_SCART_YUV",[scart-yuv])

AC_ARG_WITH(dvi,
	[  --with-dvi=NAME dvi [[dvi......]]],
	[HAVE_DVI="$withval"],[HAVE_DVI="true"])
AC_SUBST(HAVE_DVI)
AC_DEFINE_UNQUOTED(HAVE_DVI,"$HAVE_DVI",[dvi])

AC_ARG_WITH(minitv,
	[  --with-minitv=NAME minitv [[minitv......]]],
	[HAVE_MINITV="$withval"],[HAVE_MINITV="true"])
AC_SUBST(HAVE_MINITV)
AC_DEFINE_UNQUOTED(HAVE_MINITV,"$HAVE_MINITV",[minitv])

AC_ARG_WITH(hdmi-in-hd,
	[  --with-hdmi-in-hd=NAME hdmi-in-hd [[hdmi-in-hd......]]],
	[HAVE_HDMI_IN_HD="$withval"],[HAVE_HDMI_IN_HD="true"])
AC_SUBST(HAVE_HDMI_IN_HD)
AC_DEFINE_UNQUOTED(HAVE_HDMI_IN_HD,"$HAVE_HDMI_IN_HD",[hdmi-in-hd])

AC_ARG_WITH(hdmi-in-fhd,
	[  --with-hdmi-in-fhd=NAME hdmi-in-fhd [[hdmi-in-fhd......]]],
	[HAVE_HDMI_IN_FHD="$withval"],[HAVE_HDMI_IN_FHD="true"])
AC_SUBST(HAVE_HDMI_IN_FHD)
AC_DEFINE_UNQUOTED(HAVE_HDMI_IN_FHD,"$HAVE_HDMI_IN_FHD",[hdmi-in-fhd])

AC_ARG_WITH(wol,
	[  --with-wol=NAME wol [[wol......]]],
	[HAVE_WOL="$withval"],[HAVE_WOL="true"])
AC_SUBST(HAVE_WOL)
AC_DEFINE_UNQUOTED(HAVE_WOL,"$HAVE_WOL",[wol])

AC_ARG_WITH(wwol,
	[  --with-wwol=NAME wwol [[wwol......]]],
	[HAVE_WWOL="$withval"],[HAVE_WWOL="true"])
AC_SUBST(HAVE_WWOL)
AC_DEFINE_UNQUOTED(HAVE_WWOL,"$HAVE_WWOL",[wwol])

AC_ARG_WITH(transcoding,
	[  --with-transcoding=NAME transcoding [[transcoding......]]],
	[HAVE_TRANSCODING_TYPE1="$withval"],[HAVE_TRANSCODING_TYPE1="true"])
AC_SUBST(HAVE_TRANSCODING_TYPE1)
AC_DEFINE_UNQUOTED(HAVE_TRANSCODING_TYPE1,"$HAVE_TRANSCODING_TYPE1",[transcoding])

AC_ARG_WITH(multitranscoding,
	[  --with-multitranscoding=NAME multitranscoding [[multitranscoding......]]],
	[HAVE_TRANSCODING_TYPE2="$withval"],[HAVE_TRANSCODING_TYPE2="true"])
AC_SUBST(HAVE_TRANSCODING_TYPE2)
AC_DEFINE_UNQUOTED(HAVE_TRANSCODING_TYPE2,"$HAVE_TRANSCODING_TYPE2",[multitranscoding])

AC_ARG_WITH(ci,
	[  --with-ci=NAME ci [[ci......]]],
	[HAVE_CI="$withval"],[HAVE_CI="true"])
AC_SUBST(HAVE_CI)
AC_DEFINE_UNQUOTED(HAVE_CI,"$HAVE_CI",[ci])

AC_ARG_WITH(machinebrand,
	[  --with-machinebrand=NAME brand name [[Vu,Xtrend,...]]],
	[MACHINE_BRAND="$withval"],[MACHINE_BRAND="Vu+"])
AC_SUBST(MACHINE_BRAND)
AC_DEFINE_UNQUOTED(MACHINE_BRAND,"$MACHINE_BRAND",[machine name])

AC_ARG_WITH(machinebuild,
	[  --with-machinebuild=NAME build name [[inihdx,inihdp,...]]],
	[MACHINE_BUILD="$withval"],[MACHINE_BUILD="inihdx"])
AC_SUBST(MACHINE_BUILD)
AC_DEFINE_UNQUOTED(MACHINE_BUILD,"$MACHINE_BUILD",[build name])

AC_ARG_WITH(machinemake,
	[  --with-machinemake=NAME build name [[ventonhdx,vusolo,...]]],
	[MACHINE_MAKE="$withval"],[MACHINE_MAKE="ventonhdx"])
AC_SUBST(MACHINE_MAKE)
AC_DEFINE_UNQUOTED(MACHINE_MAKE,"$MACHINE_MAKE",[build name])

AC_ARG_WITH(machinename,
	[  --with-machinename=NAME machine name [[Solo,Ultimo,...]]],
	[MACHINE_NAME="$withval"],[MACHINE_NAME="Ultimo"])
AC_SUBST(MACHINE_NAME)
AC_DEFINE_UNQUOTED(MACHINE_NAME,"$MACHINE_NAME",[machine name])

AC_ARG_WITH(brandoem,
	[  --with-brandoem=NAME brand oem [[DAGS,DMM,...]]],
	[BRAND_OEM="$withval"],[BRAND_OEM="dags"])
AC_SUBST(BRAND_OEM)
AC_DEFINE_UNQUOTED(BRAND_OEM,"$BRAND_OEM",[brand oem])

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

AC_ARG_WITH(imagedevbuild,
	[  --with-imagedevbuild=NAME dev build number [[628]]],
	[IMAGEDEVBUILD="$withval"],[IMAGEDEVBUILD=""])
AC_SUBST(IMAGEDEVBUILD)
AC_DEFINE_UNQUOTED(IMAGEDEVBUILD,"$IMAGEDEVBUILD",[build number])

AC_ARG_WITH(feedsurl,
	[  --with-feedsurl=NAME feeds url  [[628]]],
	[FEEDSURL="$withval"],[FEEDSURL=""])
AC_SUBST(FEEDSURL)
AC_DEFINE_UNQUOTED(FEEDSURL,"$FEEDSURL",[feeds url ])

AC_ARG_WITH(imagedir,
	[  --with-imagedir=NAME imagedir folder [[628]]],
	[IMAGEDIR="$withval"],[IMAGEDIR=""])
AC_SUBST(IMAGEDIR)
AC_DEFINE_UNQUOTED(IMAGEDIR,"$IMAGEDIR",[imagedir folder])

AC_ARG_WITH(imagefs,
	[  --with-imagefs=NAME imagefs folder [[628]]],
	[IMAGE_FSTYPES="$withval"],[IMAGE_FSTYPES=""])
AC_SUBST(IMAGE_FSTYPES)
AC_DEFINE_UNQUOTED(IMAGE_FSTYPES,"$IMAGE_FSTYPES",[imagefs folder])

AC_ARG_WITH(mtdrootfs,
	[  --with-mtdrootfs=NAME mtdrootfs number [[628]]],
	[MTD_ROOTFS="$withval"],[MTD_ROOTFS=""])
AC_SUBST(MTD_ROOTFS)
AC_DEFINE_UNQUOTED(MTD_ROOTFS,"$MTD_ROOTFS",[mtdrootfs number])

AC_ARG_WITH(mtdkernel,
	[  --with-mtdkernel=NAME mtdkernel number [[628]]],
	[MTD_KERNEL="$withval"],[MTD_KERNEL=""])
AC_SUBST(MTD_KERNEL)
AC_DEFINE_UNQUOTED(MTD_KERNEL,"$MTD_KERNEL",[mtdkernel number])

AC_ARG_WITH(rootfile,
	[  --with-rootfile=NAME rootfile name [[628]]],
	[ROOTFS_FILE="$withval"],[ROOTFS_FILE=""])
AC_SUBST(ROOTFS_FILE)
AC_DEFINE_UNQUOTED(ROOTFS_FILE,"$ROOTFS_FILE",[rootfile name])

AC_ARG_WITH(kernelfile,
	[  --with-kernelfile=NAME kernelfile name [[628]]],
	[KERNEL_FILE="$withval"],[KERNEL_FILE=""])
AC_SUBST(KERNEL_FILE)
AC_DEFINE_UNQUOTED(KERNEL_FILE,"$KERNEL_FILE",[kernelfile name])

AC_ARG_WITH(mkubifs,
	[  --with-mkubifs=NAME mkubifs number [[628]]],
	[MKUBIFS_ARGS="$withval"],[MKUBIFS_ARGS=""])
AC_SUBST(MKUBIFS_ARGS)
AC_DEFINE_UNQUOTED(MKUBIFS_ARGS,"$MKUBIFS_ARGS",[mkubifs number])

AC_ARG_WITH(ubinize,
	[  --with-ubinize=NAME ubinize number [[628]]],
	[UBINIZE_ARGS="$withval"],[UBINIZE_ARGS=""])
AC_SUBST(UBINIZE_ARGS)
AC_DEFINE_UNQUOTED(UBINIZE_ARGS,"$UBINIZE_ARGS",[ubinize number])

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

AM_CONDITIONAL(AIRDIGITAL, test `echo "$BRAND_OEM"` == "airdigital")
AM_CONDITIONAL(AZBOX, test `echo "$BRAND_OEM"` == "azbox")
AM_CONDITIONAL(BROADMEDIA, test `echo "$BRAND_OEM"` == "broadmedia")
AM_CONDITIONAL(CUBE, test `echo "$BRAND_OEM"` == "cube")
AM_CONDITIONAL(DREAMBOX, test `echo "$BRAND_OEM"` == "dreambox")
AM_CONDITIONAL(TECHNOMATE, test `echo "$BOXTYPE" | cut -b 1-2` == "tm")
AM_CONDITIONAL(IQON, test `echo "$BOXTYPE" | cut -b 1-4` == "iqon")
AM_CONDITIONAL(MEGASAT, test `echo "$BOXTYPE" | cut -b 1-4` == "mega")
AM_CONDITIONAL(VUPLUS, test `echo "$BRAND_OEM"` == "vuplus")
AM_CONDITIONAL(XTREND, test `echo "$BRAND_OEM"` == "xtrend")
AM_CONDITIONAL(DAGS, test `echo "$BRAND_OEM" | cut -b 1-4` == "dags")
AM_CONDITIONAL(GIGABLUE, test `echo "$BRAND_OEM"` == "gigablue")
AM_CONDITIONAL(ODIN, test `echo "$BRAND_OEM" | cut -b 1-4` == "odin")
AM_CONDITIONAL(MIRACLEBOX, test `echo "$BOXTYPE" | cut -b 1-2` == "mb")
AM_CONDITIONAL(INI, test `echo "$BRAND_OEM" | cut -b 1-3` == "ini")
AM_CONDITIONAL(XP, test `echo "$BRAND_OEM"` == "xp")
AM_CONDITIONAL(SKYLAKE, test `echo "$BRAND_OEM"` == "skylake")
AM_CONDITIONAL(FORMULER, test `echo "$BRAND_OEM"` == "formuler")
AM_CONDITIONAL(TRIPLEDOT, test `echo "$BRAND_OEM"` == "tripledot")
AM_CONDITIONAL(HARDKERNEL, test `echo "$BRAND_OEM"` == "hardkernel")
AM_CONDITIONAL(WETEK, test `echo "$BRAND_OEM"` == "wetek")
AM_CONDITIONAL(FULAN, test `echo "$BRAND_OEM"` == "fulan")
AM_CONDITIONAL(XCORE, test `echo "$BRAND_OEM"` == "xcore")
AM_CONDITIONAL(ALIEN, test `echo "$BOXTYPE" | cut -b 1-5` == "alien")
AM_CONDITIONAL(SEZAM, test `echo "$BOXTYPE" | cut -b 1-5` == "sezam")
AM_CONDITIONAL(XPEED, test `echo "$BOXTYPE" | cut -b 1-5` == "xpeed")
AM_CONDITIONAL(VENTON, test `echo "$BOXTYPE" | cut -b 1-6` == "venton")
AM_CONDITIONAL(ATEMIO, test `echo "$BOXTYPE" | cut -b 1-6` == "atemio")
AM_CONDITIONAL(BEYONWIZ, test `echo "$BOXTYPE" | cut -b 1-8` == "beyonwiz")
AM_CONDITIONAL(BWIDOW, test `echo "$BOXTYPE" | cut -b 1-6` == "bwidow")
AM_CONDITIONAL(FEGASUS, test `echo "$BOXTYPE" | cut -b 1-7` == "fegasus")
AM_CONDITIONAL(EBOX, test `echo "$BRAND_OEM"` == "ebox")
AM_CONDITIONAL(EDISION, test `echo "$BOXTYPE" | cut -b 1-4` == "opti")
AM_CONDITIONAL(VISIONNET, test `echo "$BOXTYPE" | cut -b 1-6` == "marvel")
AM_CONDITIONAL(JEPSSEN, test `echo "$BOXTYPE" | cut -b 1-5` == "media")
AM_CONDITIONAL(ROXXS, test `echo "$BOXTYPE" | cut -b 1-5` == "roxxs")
AM_CONDITIONAL(MEDIAART, test `echo "$BOXTYPE" | cut -b 1-4` == "mart")
AM_CONDITIONAL(NANO, test `echo "$BOXTYPE" | cut -b 1-4` == "nano")
AM_CONDITIONAL(FORCE, test `echo "$BOXTYPE" | cut -b 1-5` == "force")
AM_CONDITIONAL(VIPER, test `echo "$BOXTYPE" | cut -b 1-5` == "viper")
AM_CONDITIONAL(WORLDVISION, test `echo "$BOXTYPE" | cut -b 1-11` == "worldvision")
AM_CONDITIONAL(LUNIX, test `echo "$BOXTYPE" | cut -b 1-5` == "lunix")
AM_CONDITIONAL(TIVIAR, test `echo "$BOXTYPE" | cut -b 1-6` == "tiviar")
AM_CONDITIONAL(FUSIONHD, test "$BOXTYPE" == fusionhd)
AM_CONDITIONAL(FUSIONHDSE, test "$BOXTYPE" == fusionhdse)
AM_CONDITIONAL(REVO4K, test "$BOXTYPE" == revo4k)
AM_CONDITIONAL(GALAXY4K, test "$BOXTYPE" == galaxy4k)
AM_CONDITIONAL(ANADOL4K, test `echo "$BOXTYPE" | cut -b 1-8` == "anadol4k")
AM_CONDITIONAL(AX51, test "$BOXTYPE" == ax51)
AM_CONDITIONAL(AX60, test "$BOXTYPE" == ax60)
AM_CONDITIONAL(AXULTRA, test "$BOXTYPE" == axultra)
AM_CONDITIONAL(BCM7251S, test "$BOXTYPE" == bcm7251s)
AM_CONDITIONAL(BEYONWIZU4, test "$BOXTYPE" == beyonwizu4)
AM_CONDITIONAL(BEYONWIZV2, test "$BOXTYPE" == beyonwizv2)
AM_CONDITIONAL(CC1, test `echo "$MACHINE_BUILD"` == "cc1")
AM_CONDITIONAL(S7000, test `echo "$MACHINE_BUILD"` == "7000s")
AM_CONDITIONAL(S7100, test `echo "$MACHINE_BUILD"` == "7100s")
AM_CONDITIONAL(S7105, test `echo "$MACHINE_BUILD"` == "7105s")
AM_CONDITIONAL(S7210, test `echo "$MACHINE_BUILD"` == "7210s")
AM_CONDITIONAL(S7215, test `echo "$MACHINE_BUILD"` == "7215s")
AM_CONDITIONAL(S7220, test `echo "$MACHINE_BUILD"` == "7220s")
AM_CONDITIONAL(S7225, test `echo "$MACHINE_BUILD"` == "7225s")
AM_CONDITIONAL(S7300, test `echo "$MACHINE_BUILD"` == "7300s")
AM_CONDITIONAL(S7400, test `echo "$MACHINE_BUILD"` == "7400s")
AM_CONDITIONAL(S8100, test `echo "$MACHINE_BUILD"` == "8100s")
AM_CONDITIONAL(SOGNO, test `echo "$BOXTYPE"` == "sogno8800hd")
AM_CONDITIONAL(UNIBOXHDE, test "$BOXTYPE" == uniboxhde)
AM_CONDITIONAL(ALPHATRIPLE, test "$BOXTYPE" == alphatriple)
AM_CONDITIONAL(AXODIN, test "$MACHINE_BUILD" == axodin)
AM_CONDITIONAL(AXODINC, test "$MACHINE_BUILD" == axodinc)
AM_CONDITIONAL(AZBOXME, test "$BOXTYPE" == azboxme)
AM_CONDITIONAL(AZBOXMINIME, test "$BOXTYPE" == azboxminime)
AM_CONDITIONAL(AZBOXHD, test "$BOXTYPE" == azboxhd)
AM_CONDITIONAL(AXASHIS, test `echo "$BOXTYPE" | cut -b 1-7` == "axashis")
AM_CONDITIONAL(DM8000, test "$BOXTYPE" == dm8000)
AM_CONDITIONAL(DM7020HD, test "$BOXTYPE" == dm7020hd)
AM_CONDITIONAL(DM7020HDV2, test "$BOXTYPE" == dm7020hdv2)
AM_CONDITIONAL(DM800, test "$BOXTYPE" == dm800)
AM_CONDITIONAL(DM800SE, test "$BOXTYPE" == dm800se)
AM_CONDITIONAL(DM800SEV2, test "$BOXTYPE" == dm800sev2)
AM_CONDITIONAL(DM820, test "$BOXTYPE" == dm820)
AM_CONDITIONAL(DM500HD, test "$BOXTYPE" == dm500hd)
AM_CONDITIONAL(DM500HDV2, test "$BOXTYPE" == dm500hdv2)
AM_CONDITIONAL(DM520, test "$BOXTYPE" == dm520)
AM_CONDITIONAL(DINOBOT, test `echo "$BOXTYPE" | cut -b 1-7` == "dinobot")
AM_CONDITIONAL(FERGUSON4K, test "$BOXTYPE" == ferguson4k)
AM_CONDITIONAL(E3HD, test "$BOXTYPE" == e3hd)
AM_CONDITIONAL(E4HD, test `echo "$BOXTYPE" | cut -b 1-4` == "e4hd")
AM_CONDITIONAL(ET4X00, test "$BOXTYPE" == et4x00)
AM_CONDITIONAL(ET5X00, test "$BOXTYPE" == et5x00)
AM_CONDITIONAL(ET6X00, test "$BOXTYPE" == et6x00)
AM_CONDITIONAL(ET7X00, test "$BOXTYPE" == et7x00)
AM_CONDITIONAL(ET7X00MINI, test "$BOXTYPE" == et7x00mini)
AM_CONDITIONAL(ET9X00, test "$BOXTYPE" == et9x00)
AM_CONDITIONAL(ET8000, test "$BOXTYPE" == et8000)
AM_CONDITIONAL(ET8500, test "$BOXTYPE" == et8500)
AM_CONDITIONAL(ET10000, test "$BOXTYPE" == et10000)
AM_CONDITIONAL(GI11000, test "$BOXTYPE" == gi11000)
AM_CONDITIONAL(ENFINITY, test "$BOXTYPE" == enfinity)
AM_CONDITIONAL(EVOMINI, test "$BOXTYPE" == evomini)
AM_CONDITIONAL(EVOMINIPLUS, test "$BOXTYPE" == evominiplus)
AM_CONDITIONAL(EVOSLIM, test "$BOXTYPE" == evoslim)
AM_CONDITIONAL(EVOSLIMSE, test "$BOXTYPE" == evoslimse)
AM_CONDITIONAL(EVOSLIMT2C, test "$BOXTYPE" == evoslimt2c)
AM_CONDITIONAL(X1PLUS, test "$BOXTYPE" == x1plus)
AM_CONDITIONAL(X2PLUS, test "$BOXTYPE" == x2plus)
AM_CONDITIONAL(XCOMBO, test "$BOXTYPE" == xcombo)
AM_CONDITIONAL(BRE2ZE, test "$BOXTYPE" == bre2ze)
AM_CONDITIONAL(BRE2ZET2C, test "$BOXTYPE" == bre2zet2c)
AM_CONDITIONAL(BRE2ZE4K, test "$BOXTYPE" == bre2ze4k)
AM_CONDITIONAL(TRIPLEX, test "$BOXTYPE" == triplex)
AM_CONDITIONAL(FORMULER1, test "$BOXTYPE" == formuler1)
AM_CONDITIONAL(FORMULER3, test "$BOXTYPE" == formuler3)
AM_CONDITIONAL(GBIPBOX, test "$BOXTYPE" == gbipbox)
AM_CONDITIONAL(GBX1, test "$BOXTYPE" == gbx1)
AM_CONDITIONAL(GBX2, test "$BOXTYPE" == gbx2)
AM_CONDITIONAL(GBX3, test "$BOXTYPE" == gbx3)
AM_CONDITIONAL(GBX3H, test "$BOXTYPE" == gbx3h)
AM_CONDITIONAL(GBULTRASE, test "$BOXTYPE" == gbultrase)
AM_CONDITIONAL(GBULTRAUE, test "$BOXTYPE" == gbultraue)
AM_CONDITIONAL(GBULTRAUEH, test "$BOXTYPE" == gbultraueh)
AM_CONDITIONAL(GB800SOLO, test "$BOXTYPE" == gb800solo)
AM_CONDITIONAL(GB800SE, test "$BOXTYPE" == gb800se)
AM_CONDITIONAL(GB800UE, test "$BOXTYPE" == gb800ue)
AM_CONDITIONAL(GB800SEPLUS, test "$BOXTYPE" == gb800seplus)
AM_CONDITIONAL(GB800UEPLUS, test "$BOXTYPE" == gb800ueplus)
AM_CONDITIONAL(GBQUADPLUS, test "$BOXTYPE" == gbquadplus)
AM_CONDITIONAL(GBQUAD, test "$BOXTYPE" == gbquad)
AM_CONDITIONAL(GBQUAD4K, test "$BOXTYPE" == gbquad4k)
AM_CONDITIONAL(INIHDX, test "$MACHINE_BUILD" == inihdx)
AM_CONDITIONAL(INIHDE, test "$MACHINE_BUILD" == inihde)
AM_CONDITIONAL(INIHDP, test "$MACHINE_BUILD" == inihdp)
AM_CONDITIONAL(IQONIOS100HD, test "$BOXTYPE" == iqonios100hd)
AM_CONDITIONAL(IQONIOS200HD, test "$BOXTYPE" == iqonios200hd)
AM_CONDITIONAL(IQONIOS300HD, test "$BOXTYPE" == iqonios300hd)
AM_CONDITIONAL(IXUSSONE, test "$BOXTYPE" == ixussone)
AM_CONDITIONAL(IXUSSZERO, test "$BOXTYPE" == ixusszero)
AM_CONDITIONAL(IXUSSDUO, test "$BOXTYPE" == ixussduo)
AM_CONDITIONAL(IZIBOXONE4K, test "$BOXTYPE" == iziboxone4k)
AM_CONDITIONAL(MEDIABOX, test "$BOXTYPE" == mediabox)
AM_CONDITIONAL(MEDIABOX4K, test "$BOXTYPE" == mediabox4k)
AM_CONDITIONAL(MBTWIN, test "$BOXTYPE" == mbtwin)
AM_CONDITIONAL(HD2400, test "$MACHINE_BUILD" == hd2400)
AM_CONDITIONAL(HD1500, test "$MACHINE_BUILD" == hd1500)
AM_CONDITIONAL(HD1200, test "$MACHINE_BUILD" == hd1200)
AM_CONDITIONAL(HD1265, test "$MACHINE_BUILD" == hd1265)
AM_CONDITIONAL(HD1100, test "$MACHINE_BUILD" == hd1100)
AM_CONDITIONAL(HD11, test "$MACHINE_BUILD" == hd11)
AM_CONDITIONAL(HD500C, test "$MACHINE_BUILD" == hd500c)
AM_CONDITIONAL(HD530C, test "$MACHINE_BUILD" == hd530c)
AM_CONDITIONAL(HITUBE4K, test "$BOXTYPE" == hitube4k)
AM_CONDITIONAL(MUTANT51, test "$BOXTYPE" == mutant51)
AM_CONDITIONAL(MUTANT60, test "$BOXTYPE" == mutant60)
AM_CONDITIONAL(MUTANT61, test "$BOXTYPE" == mutant61)
AM_CONDITIONAL(ODINM6, test "$BOXTYPE" == odinm6)
AM_CONDITIONAL(ODINM7, test "$MACHINE_BUILD" == odinm7)
AM_CONDITIONAL(ODINM9, test "$MACHINE_BUILD" == odinm9)
AM_CONDITIONAL(OPTIMUSSOS1, test "$BOXTYPE" == optimussos1)
AM_CONDITIONAL(OPTIMUSSOS2, test "$BOXTYPE" == optimussos2)
AM_CONDITIONAL(OSNINO, test "$BOXTYPE" == osnino)
AM_CONDITIONAL(OSNINOPLUS, test "$BOXTYPE" == osninoplus)
AM_CONDITIONAL(OSNINOPRO, test "$BOXTYPE" == osninopro)
AM_CONDITIONAL(OSMIO4K, test "$BOXTYPE" == osmio4k)
AM_CONDITIONAL(PROTEK9900LX, test "$BOXTYPE" == 9900lx)
AM_CONDITIONAL(PUREHD, test "$BOXTYPE" == purehd)
AM_CONDITIONAL(PUREHDSE, test "$BOXTYPE" == purehdse)
AM_CONDITIONAL(SF98, test "$BOXTYPE" == sf98)
AM_CONDITIONAL(SF108, test "$BOXTYPE" == sf108)
AM_CONDITIONAL(SF128, test "$BOXTYPE" == sf128)
AM_CONDITIONAL(SF138, test "$BOXTYPE" == sf138)
AM_CONDITIONAL(SF3038, test "$BOXTYPE" == sf3038)
AM_CONDITIONAL(SF4008, test "$BOXTYPE" == sf4008)
AM_CONDITIONAL(SF5008, test "$BOXTYPE" == sf5008)
AM_CONDITIONAL(SF8008, test "$BOXTYPE" == sf8008)
AM_CONDITIONAL(SOGNO8800HD, test "$BOXTYPE" == sogno8800hd)
AM_CONDITIONAL(T2CABLE, test "$BOXTYPE" == t2cable)
AM_CONDITIONAL(TMTWINOE, test "$BOXTYPE" == tmtwin)
AM_CONDITIONAL(TM2TOE, test "$BOXTYPE" == tm2t)
AM_CONDITIONAL(TMSINGLE, test "$BOXTYPE" == tmsingle)
AM_CONDITIONAL(TMNANO, test "$BOXTYPE" == tmnano)
AM_CONDITIONAL(TMNANO2T, test "$BOXTYPE" == tmnano2t)
AM_CONDITIONAL(TMNANO3T, test "$BOXTYPE" == tmnano3t)
AM_CONDITIONAL(TMNANO2SUPER, test "$BOXTYPE" == tmnano2super)
AM_CONDITIONAL(TMNANOSE, test "$BOXTYPE" == tmnanose)
AM_CONDITIONAL(TMNANOSEPLUS, test "$BOXTYPE" == tmnanoseplus)
AM_CONDITIONAL(TMNANOSEM2, test "$BOXTYPE" == tmnanosem2)
AM_CONDITIONAL(TMNANOM3, test "$BOXTYPE" == tmnanom3)
AM_CONDITIONAL(TMNANOSEM2PLUS, test "$BOXTYPE" == tmnanosem2plus)
AM_CONDITIONAL(TMNANOSECOMBO, test "$BOXTYPE" == tmnanosecombo)
AM_CONDITIONAL(TMTWIN4K, test "$BOXTYPE" == tmtwin4k)
AM_CONDITIONAL(TM4KSUPER, test "$BOXTYPE" == tm4ksuper)
AM_CONDITIONAL(ULTRABOX, test "$BOXTYPE" == ultrabox)
AM_CONDITIONAL(ULTRAV8PLUS, test "$BOXTYPE" == ultrav8plus)
AM_CONDITIONAL(ANADOLMULTI, test "$BOXTYPE" == anadolmulti)
AM_CONDITIONAL(MAXYTEMULTI, test "$BOXTYPE" == maxytecmulti)
AM_CONDITIONAL(USTYM4KPRO, test "$BOXTYPE" == ustym4kpro)
AM_CONDITIONAL(VS1000, test "$MACHINE_BUILD" == vs1000)
AM_CONDITIONAL(VS1500, test "$MACHINE_BUILD" == vs1500)
AM_CONDITIONAL(VUUNO, test "$BOXTYPE" == vuuno)
AM_CONDITIONAL(VUULTIMO, test "$BOXTYPE" == vuultimo)
AM_CONDITIONAL(VUSOLO, test "$BOXTYPE" == vusolo)
AM_CONDITIONAL(VUSOLOSE, test "$BOXTYPE" == vusolose)
AM_CONDITIONAL(VUDUO, test "$BOXTYPE" == vuduo)
AM_CONDITIONAL(VUSOLO2, test "$BOXTYPE" == vusolo2)
AM_CONDITIONAL(VUDUO2, test "$BOXTYPE" == vuduo2)
AM_CONDITIONAL(VUDUO4K, test "$BOXTYPE" == vuduo4k)
AM_CONDITIONAL(VUZERO, test "$BOXTYPE" == vuzero)
AM_CONDITIONAL(VUZERO4K, test "$BOXTYPE" == vuzero4k)
AM_CONDITIONAL(VUSOLO4K, test "$BOXTYPE" == vusolo4k)
AM_CONDITIONAL(VUUNO4K, test "$BOXTYPE" == vuuno4k)
AM_CONDITIONAL(VUUNO4KSE, test "$BOXTYPE" == vuuno4kse)
AM_CONDITIONAL(VUULTIMO4K, test "$BOXTYPE" == vuultimo4k)
AM_CONDITIONAL(VENTONHDX, test "$BOXTYPE" == ventonhdx)
AM_CONDITIONAL(XP1000, test "$MACHINE_BUILD" == xp1000)
AM_CONDITIONAL(XP1000MAX, test "$BOXTYPE" == xp1000max)
AM_CONDITIONAL(XP1000MK, test "$BOXTYPE" == xp1000mk)
AM_CONDITIONAL(VALALINUX, test "$BOXTYPE" == valalinux)

AC_CONFIG_FILES([
Makefile

BoxBranding/Makefile
BoxBranding/lib/Makefile
BoxBranding/remotes/Makefile
BoxBranding/remotes/amiko1/Makefile
BoxBranding/remotes/amiko2/Makefile
BoxBranding/remotes/amiko3/Makefile
BoxBranding/remotes/anadol4k/Makefile
BoxBranding/remotes/ax1/Makefile
BoxBranding/remotes/ax2/Makefile
BoxBranding/remotes/ax51/Makefile
BoxBranding/remotes/ax60/Makefile
BoxBranding/remotes/axas1/Makefile
BoxBranding/remotes/axas2/Makefile
BoxBranding/remotes/axas3/Makefile
BoxBranding/remotes/azboxhd/Makefile
BoxBranding/remotes/azboxme/Makefile
BoxBranding/remotes/azboxelite/Makefile
BoxBranding/remotes/beyonwiz1/Makefile
BoxBranding/remotes/beyonwiz2/Makefile
BoxBranding/remotes/cc1/Makefile
BoxBranding/remotes/cube/Makefile
BoxBranding/remotes/dmm0/Makefile
BoxBranding/remotes/dmm1/Makefile
BoxBranding/remotes/dmm2/Makefile
BoxBranding/remotes/dinobot/Makefile
BoxBranding/remotes/e3hd/Makefile
BoxBranding/remotes/e4hd/Makefile
BoxBranding/remotes/e4hdcombo/Makefile
BoxBranding/remotes/ebox5000/Makefile
BoxBranding/remotes/edision1/Makefile
BoxBranding/remotes/edision2/Makefile
BoxBranding/remotes/edision3/Makefile
BoxBranding/remotes/evo1/Makefile
BoxBranding/remotes/evo2/Makefile
BoxBranding/remotes/evo3/Makefile
BoxBranding/remotes/evo4/Makefile
BoxBranding/remotes/evo5/Makefile
BoxBranding/remotes/evo6/Makefile
BoxBranding/remotes/evo7/Makefile
BoxBranding/remotes/evo8/Makefile
BoxBranding/remotes/et4x00/Makefile
BoxBranding/remotes/et6x00/Makefile
BoxBranding/remotes/et6500/Makefile
BoxBranding/remotes/et7x00/Makefile
BoxBranding/remotes/et7x00mini/Makefile
BoxBranding/remotes/et8000/Makefile
BoxBranding/remotes/et9500/Makefile
BoxBranding/remotes/et9x00/Makefile
BoxBranding/remotes/formuler1/Makefile
BoxBranding/remotes/fulan/Makefile
BoxBranding/remotes/g300/Makefile
BoxBranding/remotes/gb0/Makefile
BoxBranding/remotes/gb1/Makefile
BoxBranding/remotes/gb2/Makefile
BoxBranding/remotes/gb3/Makefile
BoxBranding/remotes/gi1/Makefile
BoxBranding/remotes/hd1100/Makefile
BoxBranding/remotes/hd530c/Makefile
BoxBranding/remotes/hd2400/Makefile
BoxBranding/remotes/hd60/Makefile
BoxBranding/remotes/hitube/Makefile
BoxBranding/remotes/ini0/Makefile
BoxBranding/remotes/ini1/Makefile
BoxBranding/remotes/ini2/Makefile
BoxBranding/remotes/ini3/Makefile
BoxBranding/remotes/ini4/Makefile
BoxBranding/remotes/ini5/Makefile
BoxBranding/remotes/ini6/Makefile
BoxBranding/remotes/ini7/Makefile
BoxBranding/remotes/ini8/Makefile
BoxBranding/remotes/iqon1/Makefile
BoxBranding/remotes/iqon2/Makefile
BoxBranding/remotes/iqon3/Makefile
BoxBranding/remotes/hdbox/Makefile
BoxBranding/remotes/ixussone/Makefile
BoxBranding/remotes/ixusszero/Makefile
BoxBranding/remotes/izibox/Makefile
BoxBranding/remotes/miraclebox/Makefile
BoxBranding/remotes/megasat1/Makefile
BoxBranding/remotes/megasat2/Makefile
BoxBranding/remotes/mediabox/Makefile
BoxBranding/remotes/mediabox4k/Makefile
BoxBranding/remotes/red1/Makefile
BoxBranding/remotes/red2/Makefile
BoxBranding/remotes/odinm6/Makefile
BoxBranding/remotes/odinm7/Makefile
BoxBranding/remotes/odinm9/Makefile
BoxBranding/remotes/optimuss1/Makefile
BoxBranding/remotes/optimuss2/Makefile
BoxBranding/remotes/relook/Makefile
BoxBranding/remotes/revo/Makefile
BoxBranding/remotes/protek1/Makefile
BoxBranding/remotes/protek2/Makefile
BoxBranding/remotes/qviart1/Makefile
BoxBranding/remotes/qviart2/Makefile
BoxBranding/remotes/qviart3/Makefile
BoxBranding/remotes/sab1/Makefile
BoxBranding/remotes/sf98/Makefile
BoxBranding/remotes/sf108/Makefile
BoxBranding/remotes/sf2x8/Makefile
BoxBranding/remotes/sf3038/Makefile
BoxBranding/remotes/sf5008/Makefile
BoxBranding/remotes/sf8008/Makefile
BoxBranding/remotes/sogno/Makefile
BoxBranding/remotes/triplex/Makefile
BoxBranding/remotes/tiviar1/Makefile
BoxBranding/remotes/tiviar2/Makefile
BoxBranding/remotes/tyrant/Makefile
BoxBranding/remotes/uniboxhde/Makefile
BoxBranding/remotes/tm1/Makefile
BoxBranding/remotes/tm2/Makefile
BoxBranding/remotes/tm3/Makefile
BoxBranding/remotes/tm4/Makefile
BoxBranding/remotes/tm5/Makefile
BoxBranding/remotes/tm6/Makefile
BoxBranding/remotes/uclan/Makefile
BoxBranding/remotes/visionnet/Makefile
BoxBranding/remotes/vu/Makefile
BoxBranding/remotes/vu2/Makefile
BoxBranding/remotes/vu3/Makefile
BoxBranding/remotes/vu4/Makefile
BoxBranding/remotes/wetek/Makefile
BoxBranding/remotes/wetek2/Makefile
BoxBranding/remotes/wetek3/Makefile
BoxBranding/remotes/wwio1/Makefile
BoxBranding/remotes/xcore1/Makefile
BoxBranding/remotes/xcore2/Makefile
BoxBranding/remotes/xcore3/Makefile
BoxBranding/remotes/xp1000/Makefile
BoxBranding/remotes/vala/Makefile
BoxBranding/remotes/maxytec1/Makefile
BoxBranding/remotes/fusionhd/Makefile
BoxBranding/remotes/zgemma1/Makefile
BoxBranding/remotes/zgemma2/Makefile
BoxBranding/remotes/zgemma3/Makefile
BoxBranding/remotes/zgemma4/Makefile
BoxBranding/remotes/zgemma5/Makefile
BoxBranding/remotes/zgemma6/Makefile
BoxBranding/remotes/hardkernel/Makefile

])
AC_OUTPUT
