from boxbranding import getBoxType, getMachineBrand, getMachineBuild, getBrandOEM
from Tools.StbHardware import getFPVersion
import os

boxtype = getBoxType()
machinebuild = getMachineBuild()
machinebrand = getMachineBrand()
brandoem = getBrandOEM()


class RcModel:
	def __init__(self):
		pass

	def rcIsDefault(self):
		if self.getRcFolder() != 'dmm0':
			return False
		return True

	def readFile(self, target):
		fp = open(target, 'r')
		out = fp.read()
		fp.close()
		return out.split()[0]

	def process(self, line):
		if line.lower().startswith('config.usage.rc_model='):
			parts = line.split('=')
			folder = parts[-1].rstrip()
			if os.path.isfile('/usr/share/enigma2/rc_models/'+ folder + '/rc.png') and os.path.isfile('/usr/share/enigma2/rc_models/'+ folder + '/rcpositions.xml') and os.path.isfile('/usr/share/enigma2/rc_models/'+ folder + '/remote.html'):
				return folder
		return None

	# Don't try to be clever and use E2 functions here ...
	def readE2Settings(self):
		try:
			with open('/etc/enigma2/settings') as config:
				for line in config:
					ret = self.process(line)
					if ret is not None:
						return ret
		except IOError as e:
			print "[RcModel] IOError: '/etc/enigma2/settings' cannot be opened"
		return None

	def getRcFolder(self, GetDefault=False):
		if not GetDefault:
			ret = self.readE2Settings()
			if ret is not None:
				return ret

		remotefolder = 'dmm0'
		if os.path.exists('/proc/stb/info/azmodel'):
			f = open("/proc/stb/info/model",'r')
			model = f.readline().strip()
			f.close()
			if model == "premium" or model == "premium+":
				remotefolder = 'azboxhd'
			elif model == "elite" or model == "ultra":
				remotefolder = 'azboxelite'
			elif model == "me" or model == "minime":
				remotefolder = 'azboxme'


		elif boxtype in ('alien5'):
			remotefolder = 'amiko3'
		elif boxtype in ('vipert2c','vipercombo','viperslim'):
			remotefolder = 'amiko2'
		elif boxtype in ('vipercombohdd'):
			remotefolder = 'amiko1'
		elif boxtype in ('clap4k'):
			remotefolder = 'cc1'
		elif boxtype in ('enfinity'):
			remotefolder = 'evo1'
		elif boxtype in ('alphatriple'):
			remotefolder = 'sab1'
		elif boxtype in ('sf108'):
			remotefolder = 'sf108'
		elif boxtype in ('sf3038','sf128','sf138','sf4008'):
			remotefolder = 'sf3038'
		elif boxtype in ('sf5008'):
			remotefolder = 'sf5008'
		elif boxtype in ('sf98'):
			remotefolder = 'sf98'
		elif boxtype in ('x2plus'):
			remotefolder = 'evo2'
		elif boxtype in ('xcombo', 'x1plus'):
			remotefolder = 'evo3'
		elif boxtype in ('t2cable'):
			remotefolder = 'evo4'
		elif boxtype in ('evomini', 'evominiplus'):
			remotefolder = 'evo5'
		elif boxtype in ('novaip'):
			remotefolder = 'evo6'
		elif boxtype in ('novacombo', 'novatwin'):
			remotefolder = 'evo7'
		elif boxtype in ('bre2ze','bre2ze4k','bre2zet2c'):
			remotefolder = 'wwio1'
		elif boxtype in ('tiviarmin','tiviaraplus'):
			remotefolder = 'tiviar1'
		#elif boxtype in ('tiviaraplus'):
		#	remotefolder = 'tiviar2'
		elif boxtype in ('twinboxlcd'):
			remotefolder = 'red1'
		elif boxtype in ('singleboxlcd', 'twinboxlcdci', 'twinboxlcdci5'):
			remotefolder = 'red2'
		elif boxtype in ('sf208', 'sf228', 'sf238'):
			remotefolder = 'sf2x8'
		elif boxtype in ('odin2hybrid', 'odinplus'):
			remotefolder = 'ax1'
		elif boxtype in ('ax51','axultra','ax60'):
			remotefolder = 'ax51'
		elif boxtype in ('e4hd', 'e4hdhybrid'):
			remotefolder = 'e4hd'
		elif boxtype in ('e4hdcombo','e4hdultra'):
			remotefolder = 'e4hdcombo'
		elif boxtype in ('enibox'):
			remotefolder = 'hdbox'
		elif boxtype in ('mago'):
			remotefolder = 'relook'
		elif boxtype in ('tyrant'):
			remotefolder = 'tyrant'
		elif boxtype in ('marvel1'):
			remotefolder = 'visionnet'
		elif boxtype in ('9900lx'):
			remotefolder = 'protek1'
		elif boxtype in ('9910lx','9911lx','protek4k','9920lx'):
			remotefolder = 'protek2'
		elif boxtype in ('zgemmash1', 'zgemmas2s'):
			remotefolder = 'zgemma1'
		elif boxtype in ('zgemmash2', 'zgemmass', 'zgemmaslc'):
			remotefolder = 'zgemma2'
		elif boxtype in ('zgemmah6','zgemmah4','zgemmahs', 'zgemmah2s', 'zgemmah2h','zgemmah5','zgemmah52s','zgemmah3ac','zgemmah5ac','zgemmah52tc','zgemmah32tc','zgemmah7','zgemmah7s','zgemmah7c','zgemmah52splus', 'zgemmah2splus','zgemmai55plus','zgemmah92h','zgemmah92s','zgemmah9combo','zgemmah9twin'):
			remotefolder = 'zgemma3'
		elif boxtype in ('zgemmai55'):
			remotefolder = 'zgemma5'
		elif boxtype in ('zgemmah9s','zgemmah9t','zgemmah9splus'):
			remotefolder = 'zgemma6'
		elif boxtype in ('dinobot4kmini','dinobot4kplus','dinobot4k','dinobot4kse','dinobot4kl','ferguson4k','dinobot4kpro','dinobotu55','dinoboth265'):
			remotefolder = 'dinobot'
		elif boxtype in ('axashis4kcombo','axashis4kcomboplus'):
			remotefolder = 'axas1'
		elif boxtype in ('gbquad', 'gb800se', 'gb800ue', 'gb800solo', 'gb800seplus', 'gb800ueplus', 'gbipbox', 'gbultrase', 'gbultraue', 'gbx1', 'gbx3'):
			remotefolder = 'gb0'
		elif boxtype == 'gbquadplus':
			remotefolder = 'gb1'
		elif boxtype in ('gbx2', 'gbx3h', 'gbultraueh'):
			remotefolder = 'gb2'
		elif boxtype in ('gbquad4k','gbue4k','gbtrio4k'):
			remotefolder = 'gb3'
		elif boxtype in ('mutant11', 'mutant1100', 'mutant1200', 'mutant500c', 'vizyonvita', 'mutant1265', 'mutant1500', 'mutant51', 'bcm7251s', 'vimastec1000', 'vimastec1500'):
			remotefolder = 'hd1100'
		elif boxtype in ('mutant530c'):
			remotefolder = 'hd530c'
		elif boxtype in ('mutant60','mutant61'):
			remotefolder = 'hd60'
		elif boxtype in ('mutant2400', 'quadbox2400', 'bcm7252'):
			remotefolder = 'hd2400'
		elif boxtype in ('revo4k','galaxy4k'):
			remotefolder = 'revo'
		elif boxtype in ('anadol4k','anadol4kv2','anadol4kcombo'):
			remotefolder = 'anadol4k'
		elif boxtype in ('mediabox4k'):
			remotefolder = 'mediabox4k'
		elif boxtype in ('mediabox'):
			remotefolder = 'mediabox'
		elif machinebrand == 'XSARIUS':
			remotefolder = 'fusionhd'
		elif boxtype in ('force4','iqonios100hd', 'iqonios200hd', 'iqonios300hd', 'iqonios300hdv2', 'roxxs200hd', 'mediaart200hd', 'force2se', 'force2', 'force2plus', 'force2plushv', 'force2nano'):
			remotefolder = 'iqon1'
		elif boxtype in ('force1', 'force1plus', 'worldvisionf1', 'worldvisionf1plus'):
			remotefolder = 'iqon2'
		elif boxtype in ('force3uhdplus','force3uhd'):
			remotefolder = 'iqon3'
		elif boxtype in ('lunix34k','lunix'):
			remotefolder = 'qviart1'
		elif boxtype in ('lunix4k'):
			remotefolder = 'qviart3'
		elif boxtype in ('formuler1', 'formuler3', 'formuler4', 'formuler4turbo', 'formuler1tc', 'formuler3ip', 'formuler4ip'):
			remotefolder = 'formuler1'
		elif boxtype in ('triplex', 'ultrabox'):
			remotefolder = 'triplex'
		elif boxtype == 'dm8000':
			remotefolder = 'dmm0'
		elif boxtype in ('dm800', 'dm800se', 'dm500hd'):
			remotefolder = 'dmm1'
		elif boxtype in ('dm7080', 'dm7020hd', 'dm7020hdv2', 'dm800sev2', 'dm500hdv2', 'dm820', 'dm520', 'dm525', 'dm900', 'dm920'):
			remotefolder = 'dmm2'
		elif boxtype in ('tmtwin', 'tm2t'):
			remotefolder = 'tm1'
		elif boxtype in ('tmsingle', 'tmnano', 'tmnano2t', 'tmnano3t', 'tmnano2super'):
			remotefolder = 'tm2'
		elif boxtype in ('tmnanose', 'tmnanosecombo'):
			remotefolder = 'tm3'
		elif boxtype in ('tmnanosem2', 'tmnanoseplus','tmnanosem2plus'):
			remotefolder = 'tm4'
		elif boxtype in ('tmnanom3'):
			remotefolder = 'tm5'
		elif boxtype in ('tmtwin4k','tm4ksuper'):
			remotefolder = 'tm6'
		elif boxtype == 'uniboxhd1':
			fp_version = str(getFPVersion())
			if fp_version.startswith('1'):
				remotefolder = 'ini0'
			else:
				remotefolder = 'ini2'
		elif boxtype in ('uniboxhd2', 'uniboxhd3'):
			remotefolder = 'ini1'
		elif boxtype == 'uniboxhde':
			remotefolder = 'uniboxhde'
		elif boxtype in ('sezam1000hd', 'sezam5000hd'):
			remotefolder = 'ini2'
		elif boxtype in ('xpeedlxcs2', 'xpeedlxcc'):
			remotefolder = 'gi1'
		elif machinebrand == 'Miraclebox':
			if boxtype in ('mbmicro', 'mbmicrov2', 'mbtwinplus'):
				remotefolder = 'miraclebox'
			else:
				remotefolder = 'ini3'
		elif boxtype in ('xpeedlx', 'xpeedlx1', 'xpeedlx2', 'xpeedlx3', 'atemio5x00', 'atemio6000', 'atemio6100', 'atemio6200', 'atemionemesis', 'sezammarvel'):
			remotefolder = 'ini4'
		elif boxtype in ('beyonwizt3'):
			remotefolder = 'ini5'
		elif boxtype in ('beyonwizt2', 'beyonwizt4'):
			remotefolder = 'ini7'
		elif boxtype in ('beyonwizu4'):
			remotefolder = 'beyonwiz1'
		elif boxtype in ('beyonwizv2'):
			remotefolder = 'beyonwiz2'
		elif machinebrand in ('SPACE', 'FEGASUS') or boxtype in ('xpeedlxpro'):
			remotefolder = 'ini6'
		elif boxtype in ('opticumtt'):
			remotefolder = 'ini8'
		elif boxtype in ('megaforce2'):
			remotefolder = 'megasat1'
		elif boxtype in ('megaforce1plus'):
			remotefolder = 'megasat2'
		elif boxtype in ('optimussos', 'optimussos1', 'optimussos2', 'optimussos1plus', 'optimussos2plus'):
			remotefolder = 'optimuss1'
		elif boxtype in ('optimussos3plus'):
			remotefolder = 'optimuss2'
		elif boxtype == 'sogno8800hd':
			remotefolder = 'sogno'
		elif boxtype in ('et4x00'):
			remotefolder = 'et4x00'
		elif boxtype in ('et6x00', 'et6000', 'et5x00', 'et5000'):
			remotefolder = 'et6x00'
		elif boxtype == 'et6500':
			remotefolder = 'et6500'
		elif boxtype in ('et8000', 'et8500' , 'et8500s', 'et10000'):
			remotefolder = 'et8000'
		elif boxtype in ('et9000', 'et9x00', 'et9200'):
			remotefolder = 'et9x00'
		elif boxtype in ('et9500'):
			remotefolder = 'et9500'
		elif boxtype in ('et7000', 'et7500', 'et7100'):
			remotefolder = 'et7x00'
		elif boxtype in ('et7x00mini','gi11000'):
			remotefolder = 'et7x00mini'
		elif boxtype in ('vusolo', 'vusolo2', 'vusolose', 'vuduo', 'vuuno', 'vuzero', 'vusolo4k', 'vuuno4k', 'vuultimo4k'):
			remotefolder = 'vu'
		elif boxtype == 'vuultimo':
			remotefolder = 'vu2'
		elif boxtype == 'vuduo2':
			remotefolder = 'vu3'
		elif  boxtype in ('vuuno4kse', 'vuzero4k', 'vuduo4k'):
			remotefolder = 'vu4'
		elif boxtype in ('starsatlx', 'axodin', 'axodinc', 'odinm6'):
			remotefolder = 'odinm6'
		elif boxtype in ('ixussone'):
			remotefolder = 'ixussone'
		elif boxtype in ('ixusszero'):
			remotefolder = 'ixusszero'
		elif boxtype in ('bcm7358', 'vp7358ci'):
			remotefolder = 'xcore2'
		elif boxtype in ('spycat','spycatmini','spycatminiplus','spycat4kmini','spycat4k','spycat4kcombo'):
			remotefolder = 'xcore1'
		elif boxtype in ('osmini', 'osminiplus', 'osmega'):
			remotefolder = 'xcore3'
		elif boxtype in ('osnino','osninoplus'):
			remotefolder = 'edision1'
		elif boxtype in ('osninopro'):
			remotefolder = 'edision2'
		elif boxtype in ('osmio4k'):
			remotefolder = 'edision3'
		elif machinebuild == 'cube':
			remotefolder = 'cube'
		elif machinebuild.startswith('ebox'):
			remotefolder = 'ebox5000'
		elif machinebuild == 'e3hd':
			remotefolder = 'e3hd'
		elif machinebuild == 'odinm7':
			remotefolder = 'odinm7'
		elif machinebuild == 'odinm9':
			remotefolder = 'odinm9'
		elif machinebuild == 'xp1000':
			remotefolder = 'xp1000'
		elif brandoem == 'fulan':
			remotefolder = 'fulan'
		elif boxtype in ('sf8008','sf8008s','sf8008t'):
			remotefolder = 'sf8008'
		elif boxtype in ('ustym4kpro'):
			remotefolder = 'uclan'
		elif boxtype in ('evoslim','evoslimse','evoslimt2c'):
			remotefolder = 'evo8'
		elif boxtype in ('wetekplay'):
			remotefolder = 'wetek'
		elif boxtype in ('wetekplay2'):
			remotefolder = 'wetek2'
		elif boxtype in ('wetekhub'):
			remotefolder = 'wetek3'
		elif boxtype in ('odroidc2'):
			remotefolder = 'hardkernel'
		elif boxtype in ('valalinux'):
			remotefolder = 'vala'
		elif boxtype in ('ultrav8plus','anadolmulti','maxytecmulti'):
			remotefolder = 'maxytec1'
		elif boxtype in ('iziboxone4k'):
			remotefolder = 'izibox'
		elif boxtype in ('hitube4k'):
			remotefolder = 'hitube'

		return remotefolder
		
	def getRcLocation(self):
		baselocation = '/usr/share/enigma2/rc_models/'
		remotefolder = self.getRcFolder()
		return baselocation + remotefolder + '/'

rc_model = RcModel()
