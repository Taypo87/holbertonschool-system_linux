#include "cpython.h"
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
	char *bytecheck = "bytes";

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
			 if (strncmp(type->tp_name, bytecheck, 5) == 0)
			 {
				print_python_bytes(element);
			 }
		}
	}
}

void print_python_bytes(PyObject *p)
// bytes object info, size, try string, and up to first 10 bytes
{
	Py_ssize_t size, i = 0, byteprint;
	char *byteString;

	if (PyBytes_Check(p) == 1)
	{
		size = PyBytes_Size(p);
		printf("[.] bytes object info\n");
		printf("  size: %d\n", (int)size);
		byteString = PyBytes_AsString(p);
		printf("  trying string: %s\n", byteString);
		//check size, print size unless its larger than 10, then just print 10
		for(i = 0; i <= 10 && i <= size; i++)
		{
			byteprint = i;
		}
		if (byteprint >= 10)
		{
			printf("  first 10 bytes: ");
			byteprint = 9;
		}
		
		else
			printf("  first %zd bytes: ", (byteprint + 1));
		for(i = 0; i <= (byteprint) && i <= 10; i++)
		{
			if (i < 10 && (i != (byteprint)))
				printf("%02x ", (unsigned char)byteString[i]);
			else
				printf("%02x", (unsigned char)byteString[i]);
		}
		printf("\n");

	}
	else
	{
		printf("[.] bytes object info\n");
		printf("  [ERROR] Invalid Bytes Object\n");
	}
}
