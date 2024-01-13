#include <Python.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);

/**
 * print_python_list - Prints basic info
 * @p: A PyObject list object
 */
void print_python_list(PyObject *p)
{
        int s, a, y;
        const char *type;
        PyListObject *list = (PyListObject *)p;
        PyVarObject *var = (PyVarObject *)p;

        s = var->ob_size;
        a = list->allocated;

        printf("[*] Python list info\n");
        printf("[*] Size of the Python List = %d\n", s);
        printf("[*] Allocated = %d\n", a);

        for (y = 0; y < s; y++)
        {
                type = list->ob_item[y]->ob_type->tp_name;
                printf("Element %d: %s\n", y, type);
                if (strcmp(type, "bytes") == 0)
                        print_python_bytes(list->ob_item[y]);
        }
}

/**
 * print_python_bytes - Prints basic info
 * @p: A PyObject byte object
 */
void print_python_bytes(PyObject *p)
{
        unsigned char y, s;
        PyBytesObject *bytes = (PyBytesObject *)p;

        printf("[.] bytes object info\n");
        if (strcmp(p->ob_type->tp_name, "bytes") != 0)
        {
                printf("  [ERROR] Invalid Bytes Object\n");
                return;
        }

        printf("  size: %ld\n", ((PyVarObject *)p)->ob_size);
        printf("  trying string: %s\n", bytes->ob_sval);

        if (((PyVarObject *)p)->ob_size > 10)
                s = 10;
        else
                s = ((PyVarObject *)p)->ob_size + 1;

        printf("  first %d bytes: ", s);
        for (y = 0; y < s; y++)
        {
                printf("%02hhx", bytes->ob_sval[y]);
                if (y == (s - 1))
                        printf("\n");
                else
                        printf(" ");
        }
}