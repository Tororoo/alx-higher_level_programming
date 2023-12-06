#define PY_SSIZE_T_CLEAN
#include <Python.h>

void print_python_bytes(PyObject *p)
{
    PyBytesObject *bytes;
    Py_ssize_t size, i;
    unsigned char *string;

    printf("[.] bytes object info\n");

    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    bytes = (PyBytesObject *)p;
    size = PyBytes_Size(p);
    string = PyBytes_AsString(p);

    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", string);

    printf("  first %ld bytes: ", size < 10 ? size : 10);
    for (i = 0; i < size && i < 10; ++i)
        printf("%02x%c", string[i], i + 1 < size ? ' ' : '\n');
}

void print_python_list(PyObject *p)
{
    PyListObject *list;
    Py_ssize_t size, i;
    PyObject *item;

    printf("[*] Python list info\n");

    if (!PyList_Check(p))
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    list = (PyListObject *)p;
    size = PyList_Size(p);

    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", list->allocated);

    for (i = 0; i < size; ++i)
    {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, item == NULL ? "NULL" : item->ob_type->tp_name);
        if (PyBytes_Check(item))
            print_python_bytes(item);
    }
}
