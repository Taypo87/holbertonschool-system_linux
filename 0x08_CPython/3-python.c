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
	char *bytecheck = "bytes", *floatcheck = "float";

	if (PyList_Check(p) == 1)
	{
		len = (((PyVarObject*)(p))->ob_size);
		list = (PyListObject *)p;
		

		printf("[*] Python list info\n");
		printf("[*] Size of the Python List = %d\n", (int)len);
		printf("[*] Allocated = %d\n", (int)list->allocated);
		for (i = 0; i < len; i++)
		{
			 element = PyList_GET_ITEM(p, i);
			 type = (((PyObject*)(element))->ob_type);
			 printf("Element %d: %s\n", ((int)i), type->tp_name);
			 if (strncmp(type->tp_name, bytecheck, 5) == 0)
			 {
				print_python_bytes(element);
			 }
			 if (strncmp(type->tp_name, floatcheck, 5) == 0)
			 {
				print_python_float(element);
			 }
		}
	}
}

void print_python_bytes(PyObject *p)
// bytes object info, size, try string, and up to first 10 bytes
{
	Py_ssize_t size, i = 0, byteprint;
	char *buffer = NULL;

	if (PyBytes_Check(p) == 1)
	{
		size = PyBytes_Size(p);
		printf("[.] bytes object info\n");
		printf("  size: %d\n", (int)size);
		buffer = ((PyBytesObject*)p)->ob_sval;
		printf("  trying string: %.*s\n", (int)size, buffer);
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
				printf("%02x ", (unsigned char)buffer[i]);
			else
				printf("%02x", (unsigned char)buffer[i]);
		}
		printf("\n");

	}
	else
	{
		printf("[.] bytes object info\n");
		printf("  [ERROR] Invalid Bytes Object\n");
	}
}

void print_python_float(PyObject *p)
{
	double value;
	if (PyFloat_Check(p) == 1)
	{
		value = PyFloat_AsDouble(p);
		printf("[.] float object info\n");

		if (value == (int)value)
		{
			printf("  value: %.1f\n", value);
		}
		else
			printf("  value: %.16g\n", value);
	}
	else
	{
		printf("  [Error] Invalid Float Object\n");
	}
}
