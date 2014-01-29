from boxbranding import getBoxType, getMachineName, getMachineBrand
from Tools.StbHardware import getFPVersion
import os

class RcModel:
	RCTYPE_AZBOXHD = 0
	RCTYPE_AZBOXELITE = 1
	RCTYPE_AZBOXME = 2
	RCTYPE_CUBE = 3
	RCTYPE_DMM = 4
	RCTYPE_DMM1 = 5
	RCTYPE_DMM2 = 6
	RCTYPE_E3HD = 7
	RCTYPE_EBOX5000 = 8
	RCTYPE_ET4X00 = 9
	RCTYPE_ET6X00 = 10
	RCTYPE_ET6500 = 11
	RCTYPE_ET8000 = 12
	RCTYPE_ET9X00 = 13
	RCTYPE_ET9500 = 14
	RCTYPE_EVO = 15
	RCTYPE_GB = 16
	RCTYPE_INI0 = 17
	RCTYPE_INI1 = 18
	RCTYPE_INI2 = 19
	RCTYPE_INI3 = 20
	RCTYPE_INI4 = 21
	RCTYPE_IQON = 22
	RCTYPE_IXUSSONE = 23
	RCTYPE_IXUSSZERO = 24
	RCTYPE_MEDIABOX = 25
	RCTYPE_ODINM6 = 26
	RCTYPE_ODINM7 = 27
	RCTYPE_ODINM9 = 28
	RCTYPE_OPTIMUSS = 29
	RCTYPE_SOGNO = 30
	RCTYPE_TM = 31
	RCTYPE_VU = 32
	RCTYPE_VU2 = 33
	RCTYPE_VU3 = 34
	RCTYPE_XP1000 = 35


	def __init__(self):
		pass

	def rcIsDefault(self):
		if self.getRcType != self.RCTYPE_DMM:
			return False
		return True

	def readFile(self, target):
		fp = open(target, 'r')
		out = fp.read()
		fp.close()
		return out.split()[0]

	def readRcTypeFromProc(self):
		self.currentRcType = self.RCTYPE_DMM
		if getMachineBrand() == 'EVO':
			self.currentRcType = self.RCTYPE_EVO
		elif getMachineBrand() == 'GigaBlue':
			self.currentRcType = self.RCTYPE_GB
		elif getMachineBrand() == 'Jepssen':
			self.currentRcType = self.RCTYPE_MEDIABOX
		elif getMachineBrand() == 'Technomate':
			self.currentRcType = self.RCTYPE_TM
		elif getMachineBrand() == 'Iqon':
			self.currentRcType = self.RCTYPE_IQON
		elif getMachineBrand() == 'UNiBOX':
			if getBoxType() == 'ini-3000':
				fp_version = str(getFPVersion())
				if fp_version.startswith('1'):
					self.currentRcType = self.RCTYPE_INI0
				else:
					self.currentRcType = self.RCTYPE_INI2
			elif getBoxType() in ('ini-5000', 'ini-7000', 'ini-7012', 'ini-9000'):
				self.currentRcType = self.RCTYPE_INI1  
		elif getMachineBrand() == 'Sezam': 
			if getBoxType() in ('ini-1000ru', 'ini-5000ru'):
				self.currentRcType = self.RCTYPE_INI2
			elif getBoxType() in ('ini-9000ru'):
				self.currentRcType = self.RCTYPE_INI4
		elif getMachineBrand() == 'Miraclebox': 
			self.currentRcType = self.RCTYPE_INI3
		elif getMachineBrand() == 'GI':
			self.currentRcType = self.RCTYPE_INI4
		elif getBoxType() in ('optimussos1', 'optimussos2', 'optimussos1plus', 'optimussos2plus'):
			self.currentRcType = self.RCTYPE_OPTIMUSS
		elif getBoxType() == 'sogno-8800hd':
			self.currentRcType = self.RCTYPE_SOGNO
		elif getBoxType() in ('vusolo', 'vusolo2', 'vuduo', 'vuuno'):
			self.currentRcType = self.RCTYPE_VU
		elif getBoxType() == 'vuultimo':
			self.currentRcType = self.RCTYPE_VU2
		elif getBoxType() == 'vuduo2':
			self.currentRcType = self.RCTYPE_VU3
		elif getBoxType() == 'dm8000':
			self.currentRcType = self.RCTYPE_DMM
		elif getBoxType() in ('dm7020hd', 'dm7020hdv2', 'dm800sev2', 'dm500hdv2'):
			self.currentRcType = self.RCTYPE_DMM2
		elif getBoxType() in ('dm800', 'dm800se', 'dm500hd'):
			self.currentRcType = self.RCTYPE_DMM1
		elif getBoxType() in ('starsatlx', 'axodin', 'odinm6'):
			self.currentRcType = self.RCTYPE_ODINM6
		elif getMachineBrand() in ('Xtrend', 'Max-Digital', 'MK-Digital', 'Octagon'):
			model = self.readFile('/proc/stb/info/boxtype')
			rc = self.readFile('/proc/stb/ir/rc/type')
			if rc == '3':
				self.currentRcType = self.RCTYPE_ODINM9
			if rc == '4':
				self.currentRcType = self.RCTYPE_DMM
			elif rc == '5':
				self.currentRcType = self.RCTYPE_ET9X00
			elif rc == '6':
				self.currentRcType = self.RCTYPE_DMM
			elif rc == '7':
				self.currentRcType = self.RCTYPE_ET6X00
			elif rc == '8':
				self.currentRcType = self.RCTYPE_VU
			elif rc == '9' and model == 'et9500':
				self.currentRcType = self.RCTYPE_ET9500
			elif rc == '9' and model == 'et6500':
				self.currentRcType = self.RCTYPE_ET6500
			elif rc == '11' and model == 'et9200':
				self.currentRcType = self.RCTYPE_ET9500
			elif rc == '11' and model == 'et9000':
				self.currentRcType = self.RCTYPE_ET9x00
			elif rc == '13' and model == 'et4000':
				self.currentRcType = self.RCTYPE_ET4X00
			elif rc == '14':
				self.currentRcType = self.RCTYPE_XP1000
			elif model == 'et8000':
				self.currentRcType = self.RCTYPE_ET8000
			elif model == 'et10000':
				self.currentRcType = self.RCTYPE_ET8000
		elif os.path.exists('/proc/stb/info/azmodel'):
			f = open("/proc/stb/info/model",'r')
			model = f.readline().strip()
			f.close()
			if model == "premium" or model == "premium+":
				self.currentRcType = self.RCTYPE_AZBOXHD
			elif model == "elite" or model == "ultra":
				self.currentRcType = self.RCTYPE_AZBOXELITE
			elif model == "me" or model == "minime":
				self.currentRcType = self.RCTYPE_AZBOXME
		elif os.path.exists('/proc/stb/info/boxtype'):
			model = self.readFile('/proc/stb/info/boxtype')
			if model.startswith('ebox'):
				self.currentRcType = self.RCTYPE_EBOX5000
			elif model == 'cube':
				self.currentRcType = self.RCTYPE_CUBE
			elif model == 'e3hd':
				self.currentRcType = self.RCTYPE_E3HD
			elif model == 'odinm9':
				self.currentRcType = self.RCTYPE_ODINM9
			elif model == 'odinm7':
				self.currentRcType = self.RCTYPE_ODINM7
			elif model.startswith('Ixuss'):
				if getBoxType() == 'ixussone':
					self.currentRcType = self.RCTYPE_IXUSSONE
				elif getBoxType() == 'ixusszero':
					self.currentRcType = self.RCTYPE_IXUSSZERO

	def getRcType(self):
		self.readRcTypeFromProc()
		return self.currentRcType
		
	def getRcFolder(self):
		remotefolder = 'dmm0'
		print 'self.getRcType:',self.getRcType()
		if self.getRcType() == self.RCTYPE_AZBOXHD:
			remotefolder = 'azboxhd'
		elif self.getRcType() == self.RCTYPE_AZBOXELITE:
			remotefolder = 'azboxelite'
		elif self.getRcType() == self.RCTYPE_AZBOXME:
			remotefolder = 'azboxme'
		elif self.getRcType() == self.RCTYPE_CUBE:
			remotefolder = 'cube'
		elif self.getRcType() == self.RCTYPE_DMM:
			remotefolder = 'dmm0'
		elif self.getRcType() == self.RCTYPE_DMM1:
			remotefolder = 'dmm1'
		elif self.getRcType() == self.RCTYPE_DMM2:
			remotefolder = 'dmm2'
		elif self.getRcType() == self.RCTYPE_E3HD:
			remotefolder = 'e3hd'	
		elif self.getRcType() == self.RCTYPE_EBOX5000:
			remotefolder = 'ebox5000'
		elif self.getRcType() == self.RCTYPE_ET4X00:
			remotefolder = 'et4x00'
		elif self.getRcType() == self.RCTYPE_ET6X00:
			remotefolder = 'et6x00'
		elif self.getRcType() == self.RCTYPE_ET6500:
			remotefolder = 'et6500'
		elif self.getRcType() == self.RCTYPE_ET8000:
			remotefolder = 'et8000'
		elif self.getRcType() == self.RCTYPE_ET9X00:
			remotefolder = 'et9x00'
		elif self.getRcType() == self.RCTYPE_ET9500:
			remotefolder = 'et9500'
		elif self.getRcType() == self.RCTYPE_EVO:
			remotefolder = 'evo'
		elif self.getRcType() == self.RCTYPE_GB:
			remotefolder = 'gb'
		elif self.getRcType() == self.RCTYPE_INI0:
			remotefolder = 'ini0'
		elif self.getRcType() == self.RCTYPE_INI1:
			remotefolder = 'ini1'
		elif self.getRcType() == self.RCTYPE_INI2:
			remotefolder = 'ini2'
		elif self.getRcType() == self.RCTYPE_INI3:
			remotefolder = 'ini3'
		elif self.getRcType() == self.RCTYPE_INI4:
			remotefolder = 'ini4'
		elif self.getRcType() == self.RCTYPE_IQON:
			remotefolder = 'iqon'
		elif self.getRcType() == self.RCTYPE_IXUSSONE:
			remotefolder = 'ixussone'
		elif self.getRcType() == self.RCTYPE_IXUSSZERO:
			remotefolder = 'ixusszero'
		elif self.getRcType() == self.RCTYPE_MEDIABOX:
			remotefolder = 'mediabox'
		elif self.getRcType() == self.RCTYPE_ODINM6:
			remotefolder = 'odinm6'
		elif self.getRcType() == self.RCTYPE_ODINM7:
			remotefolder = 'odinm7'
		elif self.getRcType() == self.RCTYPE_ODINM9:
			remotefolder = 'odinm9'
		elif self.getRcType() == self.RCTYPE_OPTIMUSS:
			remotefolder = 'optimuss'
		elif self.getRcType() == self.RCTYPE_SOGNO:
			remotefolder = 'sogno'
		elif self.getRcType() == self.RCTYPE_TM:
			remotefolder = 'tm'
		elif self.getRcType() == self.RCTYPE_VU:
			remotefolder = 'vu'
		elif self.getRcType() == self.RCTYPE_VU2:
			remotefolder = 'vu2'
		elif self.getRcType() == self.RCTYPE_VU3:
			remotefolder = 'vu3'
		elif self.getRcType() == self.RCTYPE_XP1000:
			remotefolder = 'xp1000'
		return remotefolder
		
	def getRcLocation(self):
		baselocation = '/usr/share/enigma2/rc_models/'
		remotefolder = self.getRcFolder()
		return baselocation + remotefolder + '/'

rc_model = RcModel()
