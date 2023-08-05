#include "cpython.h"

void print_python_list(PyObject *p)
{
    Py_ssize_t len, i = 0, refcount;
    PyTypeObject *type;
    PyObject *element;

    // looks like we need size of python list,  allocated, and the elements of the list and their type
    if (PyList_Check(p) == 1)
    {
        len = PyList_Size(p);
        refcount = Py_REFCNT(p);

        printf("[*] Python list info\n");
        printf("[*] Size of the Python list = %d\n", (int)len);
        printf("[*] Allocated = %d\n", (int)refcount);
        for (i = 0; i < len; i++)
        {
             element = PyList_GetItem(p, i);
             type = Py_TYPE(element);
             printf("Element %d: %s\n", ((int)i), type->tp_name);
        }
    }
}
