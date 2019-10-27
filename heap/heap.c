/**
 * @author      : alpha (alpha@mascot)
 * @created     : Friday Oct 18, 2019 00:03:03 HKT
 */
#include <stdlib.h>
#include <stdio.h>

#define parent_of(i) ((i) > 0 ? ((i) - 1) / 2 : 0)
#define left_of(i) ((i) * 2 + 1)
#define right_of(i) ((i) * 2 + 2)

#define SWAP(a, b, size)                   \
do {                                       \
    register size_t __size = (size);       \
    register char *__a = (a), *__b = (b);  \
    do {                                   \
        char __tmp = *__a;                 \
        *__a++ = *__b;                     \
        *__b++ = __tmp;                    \
    } while (--__size > 0);                \
} while (0)

#define SET(d, s, size)                    \
do {                                       \
    register size_t __size = (size);       \
    register char *__d = (d), *__s = (s);  \
    do {                                   \
        *__d++ = *__s++;                     \
    } while (--__size > 0);                \
} while (0)

struct heap_s {
	int (*compare)(const void *, const void *);
	size_t elem_count;
	size_t elem_size;
	size_t heap_count;
	char data[0];
};

static int compare(struct heap_s *heap, int i, int j)
{
	return heap->compare(&heap->data[i * heap->elem_size], &heap->data[j * heap->elem_size]);
}

static void swap(struct heap_s *heap, int i, int j)
{
	SWAP(&heap->data[i * heap->elem_size], &heap->data[j * heap->elem_size], heap->elem_size);
}

static void set(struct heap_s *heap, int i, void *elem)
{
	SET(&heap->data[i * heap->elem_size], elem, heap->elem_size);
}

static void get(struct heap_s *heap, int i, void *elem)
{
	SET(elem, &heap->data[i * heap->elem_size], heap->elem_size);
}

static void shift_up(struct heap_s *heap, int i)
{
	int s = i;
	int p = parent_of(s);
	while ((s > 0) && (compare(heap, s, p) < 0)) {
		swap(heap, p, s);
		s = p;
		p = parent_of(s);
	}
}

static void shift_down(struct heap_s *heap, int i)
{
	int p = i;
	int s = left_of(p);
	while (s < heap->heap_count) {
		int r = s + 1;
		if (r < heap->heap_count && compare(heap, r, s) < 0) {
			s = r;
		}
		if (compare(heap, s, p) < 0) {
			swap(heap, p, s);
			p = s;
			s = left_of(p);
		} else {
			break;
		}
	}
}

struct heap_s * init_heap(size_t elem_count, size_t elem_size,
			int (*compare)(const void *, const void *))
{
	struct heap_s *heap = NULL;
	size_t data_size = elem_count * elem_size;
	if (data_size > 0) {
		heap = (struct heap_s *)malloc(sizeof(struct heap_s) + data_size);
	}
	if (heap != NULL){
		heap->compare = compare;
		heap->elem_count = elem_count;
		heap->elem_size = elem_size;
		heap->heap_count = 0;
	}
	return heap;
}

void free_heap(struct heap_s *heap)
{
	free(heap);
}

void * heap_pop(struct heap_s *heap, void *elem)
{
	if (heap != NULL && heap->heap_count > 0 && elem != NULL) {
		get(heap, 0, elem);
		// printf("(%d)", *(int *)elem);
		heap->heap_count--;
		swap(heap, 0, heap->heap_count);
		// int tmp; get(heap, 0, &tmp); printf("(count:%lu, tmp head:%d) ", heap->heap_count, tmp);
		shift_down(heap, 0);
		return elem;
	}
	return NULL;
}

void * heap_push(struct heap_s *heap, void *elem)
{
	if (heap != NULL && heap->heap_count < heap->elem_count && elem != NULL) {
		set(heap, heap->heap_count, elem);
		// printf("(%lu: %d)", heap->heap_count, *((int *)&heap->data[heap->heap_count * heap->elem_size]));
		heap->heap_count++;
		shift_up(heap, heap->heap_count - 1);
		// printf("%d(%lu:%d) ", *(int *)elem, heap->heap_count, *((int *)&heap->data[0]));
		return elem;
	}
	return NULL;
}

void * heap_elem(struct heap_s *heap, int i, void *elem)
{
	if (heap != NULL && heap->heap_count > 0 && i < heap->heap_count && elem != NULL) {
		// printf("(%lu:%d %d)", heap->heap_count, i, *((int *)&heap->data[i * heap->elem_size]));
		get(heap, i, elem);
		return elem;
	}
	return NULL;
}

void * heap_head(struct heap_s *heap, void *elem)
{
	return heap_elem(heap, 0, elem);
}

int heap_count(const struct heap_s *heap)
{
	if (heap != NULL) {
		return heap->heap_count;
	}
	return -1;
}

/* =========================================================== */

int test_cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(int argc, char *argv[])
{
	int input[1000];
	int count = 0;
	while (scanf("%d", &input[count]) != EOF) {
		count++;
	}
	printf("input: %d\n", count);
	for (int i = 0; i < count; i++) {
		printf("%d ", input[i]);
	}
	printf("\n");
	struct heap_s *heap = init_heap(count, sizeof(int), test_cmp);
	if (heap == NULL) {
		printf("init heap failed.\n");
		return -1;
	}
	printf("heap push:\n");
	for (int i = 0; i < count; i++) {
		int * elem = (int *)heap_push(heap, &input[i]);
		if (elem != NULL) {
			printf("(%d %d) ", *elem, input[i]);
		}
	}
	printf("\n");
	printf("heap data:\n");
	for (int i = 0; i < heap_count(heap); i++) {
		int tmp;
		int * elem = (int *)heap_elem(heap, i, &tmp);
		if (elem != NULL) {
			printf("(%d/%d: %d) ", i, heap_count(heap), *elem);
		}
	}
	printf("\n");
	printf("heap pop:\n");
	while (heap_count(heap) > 0) {
		int tmp;
		int *elem = (int *)heap_pop(heap, &tmp);
		if (elem != NULL) {
			printf("%d ", *elem);
		}
	}
	printf("\n");
}
