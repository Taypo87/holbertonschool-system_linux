#include "cpython.h"

void print_python_string(PyObject *p)
{
    PyTypeObject *type;
    char *string = "str", *stringType;
    Py_ssize_t size;


    type = Py_TYPE(p);
    if (strncmp(type->tp_name, string, 3) == 0)
    {
        printf("[.] string object info\n");
        
        if (PyUnicode_Check(p))
        {
            size = PyUnicode_GET_LENGTH(p);
            printf("  type: compact unicode object\n");
            printf("  length: %d\n", (int)size);
            stringType = PyUnicode_AsUTF8(p);
            printf("  value: %s\n", stringType);
        }
        else
        {
            size = PyBytes_Size(p);
            printf("  type: compact ascii\n");
            printf("  length: %d\n", (int)size);
            stringType = PyBytes_AsString(p);
            printf("  value: %s\n", stringType);
        }
        

    }
    else
    {
        printf("[.] string object info\n");
        printf("  [ERROR] Invalid String Object\n");
    }
}
