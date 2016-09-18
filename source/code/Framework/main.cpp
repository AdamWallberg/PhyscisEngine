// Program written by: Adam Wallberg

#define TEST_PYTHON

#ifdef TEST_PYTHON

// Track memory leaks
#ifdef DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include "Application.h"

// python
#ifdef _DEBUG
#undef _DEBUG
#include <Python/python.h>
#define _DEBUG
#else
#include <Python/python.h>
#endif

static int numargs=0;

/* Return the number of arguments of the application command line */
static PyObject*
emb_run_application(PyObject *self, PyObject *args)
{
    if(!PyArg_ParseTuple(args, ":numargs"))
        return nullptr;

	// Create the application
	Application* app = new Application;

	// Run the application
	app->Run();

	// Delete the application
	delete app;

    return PyLong_FromLong(numargs);
}

static PyMethodDef EmbMethods[] = {
    {"run", emb_run_application, METH_VARARGS,
     "Runs the Physcis Engine framework."},
    {nullptr, nullptr, 0, nullptr}
};

static PyModuleDef EmbModule = {
    PyModuleDef_HEAD_INIT, "application", nullptr, -1, EmbMethods,
    nullptr, nullptr, nullptr, nullptr
};

static PyObject*
PyInit_emb(void)
{
    return PyModule_Create(&EmbModule);
}

int
main()
{

	int argc = 3;
	char* argv[] = { "", "run_app", "test_func" };

    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    int i;

	numargs = argc;
	PyImport_AppendInittab("application", &PyInit_emb);

    Py_Initialize();
    pName = PyUnicode_DecodeFSDefault(argv[1]);
    /* Error checking of pName left out */

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != nullptr) {
        pFunc = PyObject_GetAttrString(pModule, argv[2]);
        /* pFunc is a new reference */

        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(argc - 3);
            for (i = 0; i < argc - 3; ++i) {
                pValue = PyLong_FromLong(atoi(argv[i + 3]));
                if (!pValue) {
                    Py_DECREF(pArgs);
                    Py_DECREF(pModule);
                    fprintf(stderr, "Cannot convert argument\n");
                    return 1;
                }
                /* pValue reference stolen here: */
                PyTuple_SetItem(pArgs, i, pValue);
            }
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != nullptr) {
                printf("Result of call: %ld\n", PyLong_AsLong(pValue));
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return 1;
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", argv[2]);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
        return 1;
    }
    Py_Finalize();

#ifdef DEBUG
	// Dump memory leaks
	_CrtDumpMemoryLeaks();
#endif

    return 0;
}

#else

// Track memory leaks
#ifdef DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif


// framework
#include "Application.h"


int main()
{
	// Create the application
	Application* app = new Application;
	
	// Run the application
	app->Run();
	
	// Delete the application
	delete app;

#ifdef DEBUG
	// Dump memory leaks
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}


#endif