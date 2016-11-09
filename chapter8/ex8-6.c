#include <string.h>

typedef long Align;

union header {
	struct {
		union header *ptr;
		unsigned size;
	} s;
	Align x;
};
typedef union header Header;

static Header base;
static Header *freep = NULL;
static Header *morecore(unsigned); 
void free(void *); 
void *malloc2(unsigned);

void *calloc(size_t n, size_t size) {
	void *ptr;
    
    if (n == 0 || size == 0)
        return NULL;
    else if ((ptr = malloc2(n * size)) == NULL)
        return NULL;
    else {
        memset(ptr, 0x0, n * size);
        return ptr;
    }
}

void *malloc2(unsigned nbytes) {
	Header *p, *prevp;
	Header *moreroce(unsigned);
	unsigned nunits;

	nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
	if ((prevp = freep) == NULL) {
		base.s.ptr = freep = prevp = &base;
		base.s.size = 1;
	}
	for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
		if (p->s.size >= nunits) {
			if (p->s.size == nunits)
				prevp->s.ptr = p->s.ptr;
			else {
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *) (p + 1);
		}
		if (p == freep)
			if ((p = morecore(nunits)) == NULL)
				return NULL;
	}
}

#define NALLOC 1024

static Header *morecore(unsigned nu) {
	void *cp, *sbrk(int);
	Header *up;

	if (nu < NALLOC)
		nu = NALLOC;
	cp = sbrk(nu * sizeof(Header));
	if (cp == (void *) -1)
		return NULL;
	up = (Header *) cp;
	up->s.size = nu;
	free((void *) (up + 1));
	return freep;
}

void free(void *ap) {
	Header *bp, *p;

	bp = (Header *) ap - 1;
	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
		if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
			break;
	if (bp + bp->s.size == p->s.ptr) {
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr  =  p->s.ptr->s.ptr;
	}
	else
		bp->s.ptr = p->s.ptr;
	if (p + p->s.size == bp) {
		p->s.size += bp->s.size;
		p->s.ptr   = bp->s.ptr;
	}
	else
		p->s.ptr = bp;
	freep = p;
}

