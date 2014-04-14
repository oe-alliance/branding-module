#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <Python.h>
#include "boxbranding.h"

/* Available functions */
static PyObject* getMachineProcModel(PyObject* self)
{
    return Py_BuildValue("s", _getMachineProcModel());
}

static PyObject* getMachineBrand(PyObject* self)
{
    return Py_BuildValue("s", _getMachineBrand());
}
 
static PyObject* getMachineName(PyObject* self)
{
    return Py_BuildValue("s", _getMachineName());
}

static PyObject* getMachineBuild(PyObject* self)
{
    return Py_BuildValue("s", _getMachineBuild());
}

static PyObject* getMachineMake(PyObject* self)
{
    return Py_BuildValue("s", _getMachineMake());
}

static PyObject* getMachineMtdRoot(PyObject* self)
{
    return Py_BuildValue("s", _getMachineMtdRoot());
}

static PyObject* getMachineMtdKernel(PyObject* self)
{
    return Py_BuildValue("s", _getMachineMtdKernel());
}

static PyObject* getMachineRootFile(PyObject* self)
{
    return Py_BuildValue("s", _getMachineRootFile());
}

static PyObject* getMachineKernelFile(PyObject* self)
{
    return Py_BuildValue("s", _getMachineKernelFile());
}

static PyObject* getMachineMKUBIFS(PyObject* self)
{
    return Py_BuildValue("s", _getMachineMKUBIFS());
}

static PyObject* getMachineUBINIZE(PyObject* self)
{
    return Py_BuildValue("s", _getMachineUBINIZE());
}

static PyObject* getBoxType(PyObject* self)
{
    return Py_BuildValue("s", _getBoxType());
}

static PyObject* getBrandOEM(PyObject* self)
{
    return Py_BuildValue("s", _getBrandOEM());
}

static PyObject* getOEVersion(PyObject* self)
{
    return Py_BuildValue("s", _getOEVersion());
}

static PyObject* getDriverDate(PyObject* self)
{
    return Py_BuildValue("s", _getDriverDate());
}

static PyObject* getImageVersion(PyObject* self)
{
    return Py_BuildValue("s", _getImageVersion());
}

static PyObject* getImageBuild(PyObject* self)
{
    return Py_BuildValue("s", _getImageBuild());
}

static PyObject* getImageDistro(PyObject* self)
{
    return Py_BuildValue("s", _getImageDistro());
}

static PyObject* getImageFolder(PyObject* self)
{
    return Py_BuildValue("s", _getImageFolder());
}

static PyObject* getImageFileSystem(PyObject* self)
{
    return Py_BuildValue("s", _getImageFileSystem());
}

/* Module specification */
static PyMethodDef boxbrandingMethods[] = {
	{ "getMachineBuild", getMachineBuild, METH_NOARGS },
	{ "getMachineMake", getMachineMake, METH_NOARGS },
	{ "getMachineProcModel", getMachineProcModel, METH_NOARGS },  
	{ "getMachineBrand", getMachineBrand, METH_NOARGS },
	{ "getMachineName", getMachineName, METH_NOARGS },
	{ "getMachineMtdRoot", getMachineMtdRoot, METH_NOARGS },
	{ "getMachineKernelFile", getMachineKernelFile, METH_NOARGS },
	{ "getMachineRootFile", getMachineRootFile, METH_NOARGS },
	{ "getMachineMtdKernel", getMachineMtdKernel, METH_NOARGS },
	{ "getMachineMKUBIFS", getMachineMKUBIFS, METH_NOARGS },
	{ "getMachineUBINIZE", getMachineUBINIZE, METH_NOARGS },
	{ "getBoxType", getBoxType, METH_NOARGS },
	{ "getBrandOEM", getBrandOEM, METH_NOARGS },
	{ "getOEVersion", getOEVersion, METH_NOARGS },
	{ "getDriverDate", getDriverDate, METH_NOARGS },
	{ "getImageVersion", getImageVersion, METH_NOARGS },
	{ "getImageBuild", getImageBuild, METH_NOARGS },
	{ "getImageDistro", getImageDistro, METH_NOARGS },
	{ "getImageFolder", getImageFolder, METH_NOARGS },
	{ "getImageFileSystem", getImageFileSystem, METH_NOARGS },
	{ NULL, NULL }
};

/* Initialize the module */
void initboxbranding() {
	PyObject *m;
	m = Py_InitModule("boxbranding", boxbrandingMethods);
} 
