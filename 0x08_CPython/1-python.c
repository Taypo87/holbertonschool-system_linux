#include "cpython.h"
void
/**
* print_python_list - prints info about a given python list
* @p: the pointer to the python list object
* Return: void
*/
void print_python_list(PyObject *p)
{
	Py_ssize_t len, i = 0;
	PyTypeObject *type;
	PyObject *element;
	PyListObject *list;

	if (PyList_Check(p) == 1)
	{
		len = PyList_Size(p);
		list = (PyListObject *)p;
		

		printf("[*] Python list info\n");
		printf("[*] Size of the Python List = %d\n", (int)len);
		printf("[*] Allocated = %d\n", (int)list->allocated);
		for (i = 0; i < len; i++)
		{
			 element = PyList_GetItem(p, i);
			 type = Py_TYPE(element);
			 printf("Element %d: %s\n", ((int)i), type->tp_name);
		}
	}
}
	