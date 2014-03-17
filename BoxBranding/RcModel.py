from boxbranding import getBoxType, getMachineBrand, getMachineBuild
from Tools.StbHardware import getFPVersion
import os

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

	def getRcFolder(self):
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

		elif getMachineBrand() in ('Xtrend', 'MaxDigital', 'MK-Digital', 'Octagon'):
			rc = self.readFile('/proc/stb/ir/rc/type')
			if rc == '3':
				remotefolder = 'odinm9'
			if rc in ('4', '6'):
				remotefolder = 'dmm0'
			elif rc == '5':
				remotefolder = 'et9x00'
			elif rc == '7':
				remotefolder = 'et6x00'
			elif rc == '8':
				remotefolder = 'vu'
			elif rc == '9' and getBoxType() == 'et6500':
				remotefolder = 'et6500'
			elif rc == '9' and getBoxType() == 'et9500':
				remotefolder = 'et9500'
			elif rc == '9' and getBoxType() in ('et8000', 'et10000'):
				remotefolder = 'et8000'
			elif rc == '11' and getBoxType() == 'et9000':
				remotefolder = 'et9x00'
			elif rc == '11' and getBoxType() == 'et9200':
				remotefolder = 'et9500'
			elif rc == '13':
				remotefolder = 'et4x00'
			elif rc == '14':
				remotefolder = 'xp1000'

		elif getMachineBrand() == 'EVO':
			remotefolder = 'evo'
		elif getMachineBrand() == 'GigaBlue':
			remotefolder = 'gb'
		elif getMachineBrand() == 'Jepssen':
			remotefolder = 'mediabox'
		elif getMachineBrand() in ('Iqon', 'Roxxs', 'MediaArt'):
			remotefolder = 'iqon'

		elif getBoxType() == 'dm8000':
			remotefolder = 'dmm0'
		elif getBoxType() in ('dm800', 'dm800se', 'dm500hd'):
			remotefolder = 'dmm1'
		elif getBoxType() in ('dm7020hd', 'dm7020hdv2', 'dm800sev2', 'dm500hdv2'):
			remotefolder = 'dmm2'
		elif getBoxType() in ('tmtwin', 'tm2t'):
			remotefolder = 'tm1'
		elif getBoxType() in ('tmsingle', 'tmnano', 'tmnano2t'):
			remotefolder = 'tm2'
		elif getBoxType() == 'uniboxhd1':
			fp_version = str(getFPVersion())
			if fp_version.startswith('1'):
				remotefolder = 'ini0'
			else:
				remotefolder = 'ini2'
		elif getBoxType() in ('uniboxhd2', 'uniboxhd3'):
			remotefolder = 'ini1'  
		elif getBoxType() in ('sezam1000hd', 'sezam5000hd'):
			remotefolder = 'ini2'
		elif getMachineBrand() == 'Miraclebox': 
			remotefolder = 'ini3'
		elif getMachineBrand() in ('GI', 'Atemio') or getBoxType() in ('sezammarvel'):
			remotefolder = 'ini4'
		elif getBoxType() in ('optimussos1', 'optimussos2', 'optimussos1plus', 'optimussos2plus'):
			remotefolder = 'optimuss'
		elif getBoxType() == 'sogno8800hd':
			remotefolder = 'sogno'
		elif getBoxType() in ('vusolo', 'vusolo2', 'vuduo', 'vuuno'):
			remotefolder = 'vu'
		elif getBoxType() == 'vuultimo':
			remotefolder = 'vu2'
		elif getBoxType() == 'vuduo2':
			remotefolder = 'vu3'
		elif getBoxType() in ('starsatlx', 'axodin', 'odinm6'):
			remotefolder = 'odinm6'
		elif getBoxType() in ('ixussone'):
			remotefolder = 'ixussone'
		elif getBoxType() in ('ixusszero'):
			emotefolder = 'ixusszero'
		elif getMachineBuild() == 'cube':
			remotefolder = 'cube'
		elif getMachineBuild().startswith('ebox'):
			remotefolder = 'ebox5000'
		elif getMachineBuild() == 'e3hd':
			remotefolder = 'e3hd'
		elif getMachineBuild() == 'odinm7':
			remotefolder = 'odinm7'
		elif getMachineBuild() == 'odinm9':
			remotefolder = 'odinm9'
		elif getBoxType() in ('spark', 'spark7162'):
			remotefolder = 'spark'

		return remotefolder
		
	def getRcLocation(self):
		baselocation = '/usr/share/enigma2/rc_models/'
		remotefolder = self.getRcFolder()
		return baselocation + remotefolder + '/'

rc_model = RcModel()
