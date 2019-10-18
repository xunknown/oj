/**
 * @author      : alpha (alpha@mascot)
 * @created     : Friday Oct 18, 2019 00:03:03 HKT
 */
#include <stdio.h>

#define parent_of(i) ((i) > 0 ? ((i) - 1) / 2 : 0)
#define left_of(i) ((i) * 2 + 1)
#define right_of(i) ((i) * 2 + 2)
#define SWAP(a, b, size)                           \
do {                                               \
    register size_t __size = (size);               \
    register char *__a = (a), *__b = (b);          \
    do {                                           \
        char __tmp = *__a;                         \
          *__a++ = *__b;                           \
          *__b++ = __tmp;                          \
    } while (--__size > 0);                        \
} while (0)

struct heap_s {
	int (*compare)(void *, void *);
	void *data;
	size_t elem_size;
	size_t heap_size;
};

static int compare(struct heap_s *heap, int i, int j)
{
	return heap->compare(&heap->data[i], &heap->data[j]);
}

static void swap(struct heap_s *heap, int i, int j)
{
	SWAP(&heap->data[i], &heap->data[j], heap->elem_size);
}

void shift_up(struct heap_s *heap, int i)
{

}

void pop(struct heap_s *heap, int i)
{

}

void shift_down(struct heap_s *heap, int i)
{

}

void push(struct heap_s *heap, int i)
{

}
