#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <object.h>
#include <listobject.h>
#include <bytesobject.h>
#include <floatobject.h>
#include <string.h>
/**
 * print_python_bytes - print python
 * @p: pointer
 */
void print_python_bytes(PyObject *p)
{
	size_t x, y;
	char *str;

	setbuf(stdout, NULL);
	printf("[.] bytes object info\n");
	if (PyBytes_Check(p) == 0)
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	str = ((PyBytesObject *)(p))->ob_sval, x = PyBytes_Size(p);
	printf("  size: %ld\n  trying string: %s\n", x, str);
	x >= 10 ? x = 10 : x++;
	printf("  first %ld bytes: ", x);
	for (y = 0; y < x - 1; y++)
		printf("%02hhx ", str[y]);
	printf("%02hhx\n", str[y]);
}
/**
 * print_python_float - print python
 * @p: pointer
 */
void print_python_float(PyObject *p)
{
	char *str;
	double g;

	setbuf(stdout, NULL);
	printf("[.] float object info\n");
	if (PyFloat_Check(p) == 0)
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}
	g = ((PyFloatObject *)(p))->ob_fval;
	str = PyOS_double_to_string(f, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
	printf("  value: %s\n", str);
}
/**
 * print_python_list - print python
 * @p: pointer
 */
void print_python_list(PyObject *p)
{
	size_t i, size, j;
	const char *t;
	PyListObject *list;

	setbuf(stdout, NULL);
	printf("[*] Python list info\n");
	if (PyList_Check(p) == 0)
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}
	list = (PyListObject *)p;
	size = PyList_GET_SIZE(p);
	i = list->allocated;
	printf("[*] Size of the Python List = %ld\n[*] Allocated = %li\n", size, i);
	for (j = 0; j < size; j++)
	{
		t = (list->ob_item[j])->ob_type->tp_name;
		printf("Element %li: %s\n", j, t);
		!strcmp(t, "bytes") ? print_python_bytes(list->ob_item[j]) : (void)t;
		!strcmp(t, "float") ? print_python_float(list->ob_item[j]) : (void)t;
	}
}
