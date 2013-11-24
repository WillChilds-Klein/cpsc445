/* quaplot.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Table of constant values */

static integer c__6 = 6;
static integer c__13 = 13;
static integer c__9 = 9;
static integer c__1 = 1;
static integer c__3 = 3;

/* Main program */ int MAIN__(void)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_rsle(cilist *), e_rsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int qua_plot_graph_test__(integer *), cprinf(char 
	    *, integer *, ftnlen), cprini(char *, char *), 
	    zqua_plot_graph_test__(integer *);
    static integer ntest;

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, 0, 0 };
    static cilist io___2 = { 0, 5, 0, 0, 0 };



    cprini("stdout", "data13");

/*       SET ALL PARAMETERS */

    s_wsle(&io___1);
    do_lio(&c__9, &c__1, "ENTER ntest", (ftnlen)11);
    e_wsle();
    s_rsle(&io___2);
    do_lio(&c__3, &c__1, (char *)&ntest, (ftnlen)sizeof(integer));
    e_rsle();
    cprinf("ntest=", &ntest, (ftnlen)7);
    qua_plot_graph_test__(&ntest);

    zqua_plot_graph_test__(&ntest);
    s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */






/* Subroutine */ int qua_plot_graph_test__(integer *ntest)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double atan(doublereal), cos(doublereal), sin(doublereal);

    /* Local variables */
    extern /* Subroutine */ int quaplot2_(integer *, doublereal *, doublereal 
	    *, integer *, integer *, doublereal *, doublereal *, integer *, 
	    integer *, char *, ftnlen), quaplot3_(integer *, doublereal *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    integer *, integer *, doublereal *, doublereal *, integer *, 
	    integer *, char *, ftnlen), quaplot4_(integer *, doublereal *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    integer *, integer *, doublereal *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, integer *, char 
	    *, ftnlen), quaplot5_(integer *, doublereal *, doublereal *, 
	    integer *, integer *, doublereal *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, integer *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    doublereal *, integer *, integer *, char *, ftnlen), quagraph_(
	    integer *, doublereal *, doublereal *, integer *, integer *, char 
	    *, ftnlen);
    static doublereal h__;
    static integer i__;
    extern /* Subroutine */ int quagraph2_(integer *, doublereal *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    integer *, integer *, char *, ftnlen), quagraph3_(integer *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    integer *, integer *, char *, ftnlen), quagraph4_(integer *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    integer *, integer *, doublereal *, doublereal *, integer *, 
	    integer *, char *, ftnlen), quagraph5_(integer *, doublereal *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    integer *, integer *, doublereal *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, integer *, 
	    doublereal *, doublereal *, integer *, integer *, char *, ftnlen);
    static integer n2, n3, n4, n5;
    static doublereal x1[1000], y1[1000], x2[1000], y2[1000], x3[1000], y3[
	    1000], x4[1000], y4[1000], x5[1000], y5[1000], pi;
    static integer iw;
    static doublereal ts[1000], done;
    static integer itype1, itype2, itype3;
    extern /* Subroutine */ int quaplot_(integer *, doublereal *, doublereal *
	    , integer *, integer *, char *, ftnlen);


/*        construct the nodes to be plotted */

    done = 1.;
    pi = atan(done) * 4;
    h__ = pi * 2 / *ntest;
    i__1 = *ntest;
    for (i__ = 1; i__ <= i__1; ++i__) {

	ts[i__ - 1] = (i__ - 1) * h__;

	x1[i__ - 1] = cos(ts[i__ - 1]);
	y1[i__ - 1] = sin(ts[i__ - 1]);

	x2[i__ - 1] = x1[i__ - 1] * 2;
	y2[i__ - 1] = y1[i__ - 1] * 2;

	x3[i__ - 1] = x2[i__ - 1] * 2;
	y3[i__ - 1] = y2[i__ - 1] * 2;

	x4[i__ - 1] = x3[i__ - 1] * 2;
	y4[i__ - 1] = y3[i__ - 1] * 2;

	x5[i__ - 1] = x4[i__ - 1] * 2;
	y5[i__ - 1] = y4[i__ - 1] * 2;
/* L1200: */
    }

/*       ...test the quaplot_ subroutines */

    itype1 = 3;
    iw = 21;
    quaplot(iw, x1, y1, *ntest, itype1, "first circle*");

    itype1 = 1;
    itype2 = 2;
    itype3 = 3;

    iw = 22;
    n2 = *ntest / 2;
    quaplot2(iw, x1, y1, *ntest, itype1, x2, y2, n2, itype2, "first two "
	    "curves*");

    iw = 23;
    n3 = *ntest / 3;
    quaplot3(iw, x1, y1, *ntest, itype1, x2, y2, n2, itype2, x3, y3, n3, 
	    itype3, "first three curves*");

    iw = 24;
    n4 = *ntest / 4;
    quaplot4(iw, x1, y1, *ntest, itype1, x2, y2, n2, itype2, x3, y3, n3, 
	    itype3, x4, y4, n4, itype3, "first four curves*");

    iw = 25;
    n5 = *ntest / 5;
    quaplot5(iw, x1, y1, *ntest, itype1, x2, y2, n2, itype2, x3, y3, n3, 
	    itype3, x4, y4, n4, itype2, x5, y5, n5, itype3, "all five c"
	    "urves*");

/*       ...test the quagraph_ subroutines */

    itype1 = 3;
    iw = 31;
    quagraph(iw, ts, x1, *ntest, itype1, "first graph*");

    itype1 = 1;
    itype2 = 2;
    itype3 = 3;

    iw = 32;
    n2 = *ntest / 2 << 1;
    n2 = *ntest / 2;
    quagraph2(iw, ts, x1, *ntest, itype1, ts, y1, n2, itype2, "first two"
	    " graphs*");

    iw = 33;
    n3 = *ntest / 3 * 3;
    n3 = *ntest / 3;
    quagraph3(iw, ts, x1, *ntest, itype1, ts, y1, n2, itype2, ts, x2, n3,
	     itype3, "first three graphs*");

    iw = 34;
    n4 = *ntest / 4 << 2;
    n4 = *ntest / 4;
    quagraph4(iw, ts, x1, *ntest, itype1, ts, y1, n2, itype2, ts, x2, n3,
	     itype3, ts, y2, n4, itype3, "first four graphs*");

    iw = 35;
    n5 = *ntest / 5 * 5;
    n5 = *ntest / 5;
    quagraph5(iw, ts, x1, *ntest, itype1, ts, y1, n2, itype2, ts, x2, n3,
	     itype3, ts, y2, n4, itype2, ts, x3, n5, itype3, "all five "
	    "graphs*");

    return 0;
} /* qua_plot_graph_test__ */






/* Subroutine */ int zqua_plot_graph_test__(integer *ntest)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double atan(doublereal), cos(doublereal), sin(doublereal);

    /* Local variables */
    extern /* Subroutine */ int zquaplot_(integer *, doublereal *, integer *, 
	    integer *, char *, ftnlen);
    static doublereal h__;
    static integer i__;
    extern /* Subroutine */ int zquaplot2_(integer *, doublereal *, integer *,
	     integer *, doublereal *, integer *, integer *, char *, ftnlen), 
	    zquaplot3_(integer *, doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *, doublereal *, integer *, 
	    integer *, char *, ftnlen), zquaplot4_(integer *, doublereal *, 
	    integer *, integer *, doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *, doublereal *, integer *, 
	    integer *, char *, ftnlen), zquaplot5_(integer *, doublereal *, 
	    integer *, integer *, doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *, doublereal *, integer *, 
	    integer *, doublereal *, integer *, integer *, char *, ftnlen);
    static integer n2, n3, n4, n5;
    static doublereal x1[1000], y1[1000], x2[1000], y2[1000], x3[1000], y3[
	    1000], x4[1000], y4[1000], x5[1000], y5[1000], z1[2000]	/* 
	    was [2][1000] */, z2[2000]	/* was [2][1000] */, z3[2000]	/* 
	    was [2][1000] */, z4[2000]	/* was [2][1000] */, z5[2000]	/* 
	    was [2][1000] */;
    extern /* Subroutine */ int zquagraph_(integer *, doublereal *, integer *,
	     integer *, char *, ftnlen);
    static doublereal pi;
    static integer iw;
    extern /* Subroutine */ int zquagraph2_(integer *, doublereal *, integer *
	    , integer *, doublereal *, integer *, integer *, char *, ftnlen), 
	    zquagraph3_(integer *, doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *, doublereal *, integer *, 
	    integer *, char *, ftnlen), zquagraph4_(integer *, doublereal *, 
	    integer *, integer *, doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *, doublereal *, integer *, 
	    integer *, char *, ftnlen), zquagraph5_(integer *, doublereal *, 
	    integer *, integer *, doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *, doublereal *, integer *, 
	    integer *, doublereal *, integer *, integer *, char *, ftnlen);
    static doublereal ts[1000], done;
    static integer itype1, itype2, itype3;


/*        construct the nodes to be plotted */

    done = 1.;
    pi = atan(done) * 4;
    h__ = pi * 2 / *ntest;
    i__1 = *ntest;
    for (i__ = 1; i__ <= i__1; ++i__) {

	ts[i__ - 1] = (i__ - 1) * h__;

	x1[i__ - 1] = cos(ts[i__ - 1]);
	y1[i__ - 1] = sin(ts[i__ - 1]);

	x2[i__ - 1] = x1[i__ - 1] * 2;
	y2[i__ - 1] = y1[i__ - 1] * 2;

	x3[i__ - 1] = x2[i__ - 1] * 2;
	y3[i__ - 1] = y2[i__ - 1] * 2;

	x4[i__ - 1] = x3[i__ - 1] * 2;
	y4[i__ - 1] = y3[i__ - 1] * 2;

	x5[i__ - 1] = x4[i__ - 1] * 2;
	y5[i__ - 1] = y4[i__ - 1] * 2;

	z1[(i__ << 1) - 2] = x1[i__ - 1];
	z1[(i__ << 1) - 1] = y1[i__ - 1];

	z2[(i__ << 1) - 2] = x2[i__ - 1];
	z2[(i__ << 1) - 1] = y2[i__ - 1];

	z3[(i__ << 1) - 2] = x3[i__ - 1];
	z3[(i__ << 1) - 1] = y3[i__ - 1];

	z4[(i__ << 1) - 2] = x4[i__ - 1];
	z4[(i__ << 1) - 1] = y4[i__ - 1];

	z5[(i__ << 1) - 2] = x5[i__ - 1];
	z5[(i__ << 1) - 1] = y5[i__ - 1];
/* L1200: */
    }

/* cc        call prin2('x1=*',x1,ntest) */
/* cc        call prin2('y1=*',y1,ntest) */

/* cc        call prin2('z1=*',z1,2*ntest) */

/*       ...test the zquaplot_ subroutines */

    itype1 = 1;
    itype2 = 2;
    itype3 = 3;

    iw = 41;
    zquaplot_(&iw, z1, ntest, &itype3, "first circle*", (ftnlen)13);

    iw = 42;
    n2 = *ntest / 2;
    zquaplot2_(&iw, z1, ntest, &itype1, z2, &n2, &itype2, "first two curves*",
	     (ftnlen)17);

    iw = 43;
    n3 = *ntest / 3;
    zquaplot3_(&iw, z1, ntest, &itype1, z2, &n2, &itype2, z3, &n3, &itype3, 
	    "first three curves*", (ftnlen)19);

    iw = 44;
    n4 = *ntest / 4;
    zquaplot4_(&iw, z1, ntest, &itype1, z2, &n2, &itype2, z3, &n3, &itype3, 
	    z4, &n4, &itype3, "first four curves*", (ftnlen)18);

    iw = 45;
    n5 = *ntest / 5;
    zquaplot5_(&iw, z1, ntest, &itype1, z2, &n2, &itype2, z3, &n3, &itype3, 
	    z4, &n4, &itype2, z5, &n5, &itype3, "all five curves*", (ftnlen)
	    16);

/*       ...test the zquagraph_ subroutines */

    itype1 = 1;
    itype2 = 2;
    itype3 = 3;

    iw = 51;
    zquagraph_(&iw, z1, ntest, &itype3, "first circle*", (ftnlen)13);

    iw = 52;
    n2 = *ntest / 2;
    zquagraph2_(&iw, z1, ntest, &itype1, z2, &n2, &itype2, "first two curves*"
	    , (ftnlen)17);

    iw = 53;
    n3 = *ntest / 3;
    zquagraph3_(&iw, z1, ntest, &itype1, z2, &n2, &itype2, z3, &n3, &itype3, 
	    "first three curves*", (ftnlen)19);

    iw = 54;
    n4 = *ntest / 4;
    zquagraph4_(&iw, z1, ntest, &itype1, z2, &n2, &itype2, z3, &n3, &itype3, 
	    z4, &n4, &itype3, "first four curves*", (ftnlen)18);

    iw = 55;
    n5 = *ntest / 5;
    zquagraph5_(&iw, z1, ntest, &itype1, z2, &n2, &itype2, z3, &n3, &itype3, 
	    z4, &n4, &itype2, z5, &n5, &itype3, "all five curves*", (ftnlen)
	    16);

    return 0;
} /* zqua_plot_graph_test__ */




/* ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc */

/*        This is the end of the testing code, and the */
/*        beginning of the plotting code proper. */

/* ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc */

int quaplot(integer iw, doublereal *x, doublereal *y, 
	integer n, integer itype1, char *title)
{
    quaplot_(&iw,x,y,&n,&itype1,title,(ftnlen)1000);
    return 0;
}

int quaplot2(integer iw, doublereal *x, doublereal *y, 
	integer n, integer itype1, doublereal *x2, doublereal *y2, integer 
	n2, integer itype2, char *title)
{
    quaplot2_(&iw,x,y,&n,&itype1,x2,y2,&n2,&itype2,title,(ftnlen)1000);
    return 0;
}


int quaplot3(integer iw, doublereal *x, doublereal *y, 
	integer n, integer itype1, doublereal *x2, doublereal *y2, integer 
	n2, integer itype2, doublereal *x3, doublereal *y3, integer n3, 
	integer itype3, char *title)
{
    quaplot3_(&iw,x,y,&n,&itype1,x2,y2,&n2,&itype2,
            x3,y3,&n3,&itype3,title,(ftnlen)1000);
    return 0;
}

int quaplot4(integer iw, doublereal *x, doublereal *y, 
	integer n, integer itype1, doublereal *x2, doublereal *y2, integer 
	n2, integer itype2, doublereal *x3, doublereal *y3, integer n3, 
	integer itype3, doublereal *x4, doublereal *y4, integer n4, integer 
	itype4, char *title)
{
    quaplot4_(&iw,x,y,&n,&itype1,
            x2,y2,&n2,&itype2,
            x3,y3,&n3,&itype3,
            x4,y4,&n4,&itype4,title,(ftnlen)1000);
    return 0;
}
    
int quaplot5(integer iw, doublereal *x, doublereal *y, 
	integer n, integer itype1, doublereal *x2, doublereal *y2, integer 
	n2, integer itype2, doublereal *x3, doublereal *y3, integer n3, 
	integer itype3, doublereal *x4, doublereal *y4, integer n4, integer 
	itype4, doublereal *x5, doublereal *y5, integer n5, integer itype5,
	 char *title)
{
    quaplot5_(&iw,x,y,&n,&itype1,
            x2,y2,&n2,&itype2,
            x3,y3,&n3,&itype3,
            x4,y4,&n4,&itype4,
            x5,y5,&n5,&itype5,
            title,(ftnlen)1000);
    return 0;
}

int quagraph(integer iw, doublereal *x, doublereal *y, 
	integer n, integer itype1, char *title)
{
    quagraph_(&iw,x,y,&n,&itype1,title,(ftnlen)1000);
    return 0;
}

int quagraph2(integer iw, doublereal *x, doublereal *y, 
	integer n, integer itype1, doublereal *x2, doublereal *y2, integer 
	n2, integer itype2, char *title)
{
    quagraph2_(&iw,x,y,&n,&itype1,
               x2,y2,&n2,&itype2,
               title,(ftnlen)1000);
}

int quagraph3(integer iw, doublereal *x, doublereal *y, 
	integer n, integer itype1, doublereal *x2, doublereal *y2, integer 
	n2, integer itype2, doublereal *x3, doublereal *y3, integer n3, 
	integer itype3, char *title)
{
    quagraph3_(&iw,x,y,&n,&itype1,
               x2,y2,&n2,&itype2,
               x3,y3,&n3,&itype3,
               title,(ftnlen)1000);
}

int quagraph4(integer iw, doublereal *x, doublereal *y, 
	integer n, integer itype1, doublereal *x2, doublereal *y2, integer 
	n2, integer itype2, doublereal *x3, doublereal *y3, integer n3, 
	integer itype3, doublereal *x4, doublereal *y4, integer n4, integer 
	itype4, char *title)
{
    quagraph4_(&iw,x,y,&n,&itype1,
               x2,y2,&n2,&itype2,
               x3,y3,&n3,&itype3,
               x4,y4,&n4,&itype4,
               title,(ftnlen)1000);
}

int quagraph5(integer iw, doublereal *x, doublereal *y, 
	integer n, integer itype1, doublereal *x2, doublereal *y2, integer 
	n2, integer itype2, doublereal *x3, doublereal *y3, integer n3, 
	integer itype3, doublereal *x4, doublereal *y4, integer n4, integer 
	itype4, doublereal *x5, doublereal *y5, integer n5, integer itype5,
	 char *title)
{
    quagraph5_(&iw,x,y,&n,&itype1,
               x2,y2,&n2,&itype2,
               x3,y3,&n3,&itype3,
               x4,y4,&n4,&itype4,
               x5,y5,&n5,&itype5,
               title,(ftnlen)1000);
}


/* cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
 *
 *          This is the end of the wrapper code.
 *
 * cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc */


/* Subroutine */ int quaplot_(integer *iw, doublereal *x, doublereal *y, 
	integer *n, integer *itype1, char *title, ftnlen title_len)
{
    static integer n2, n3, n4, n5;
    static doublereal x2[1], y2[1], x3[1], y3[1], x4[1], y4[1], x5[1], y5[1];
    static integer itype2, itype3, itype4, itype5, inumgr;
    extern /* Subroutine */ int quaplo0_(integer *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);


    /* Parameter adjustments */
    --title;
    --y;
    --x;

    /* Function Body */
    inumgr = 1;

    quaplo0_(iw, &x[1], &y[1], x2, y2, x3, y3, x4, y4, x5, y5, n, &n2, &n3, &
	    n4, &n5, title + 1, &inumgr, itype1, &itype2, &itype3, &itype4, &
	    itype5, (ftnlen)1);

    return 0;
} /* quaplot_ */






/* Subroutine */ int quaplot2_(integer *iw, doublereal *x, doublereal *y, 
	integer *n, integer *itype1, doublereal *x2, doublereal *y2, integer *
	n2, integer *itype2, char *title, ftnlen title_len)
{
    static integer n3, n4, n5;
    static doublereal x3[1], y3[1], x4[1], y4[1], x5[1], y5[1];
    static integer itype3, itype4, itype5, inumgr;
    extern /* Subroutine */ int quaplo0_(integer *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);


    /* Parameter adjustments */
    --title;
    --y2;
    --x2;
    --y;
    --x;

    /* Function Body */
    inumgr = 2;

    quaplo0_(iw, &x[1], &y[1], &x2[1], &y2[1], x3, y3, x4, y4, x5, y5, n, n2, 
	    &n3, &n4, &n5, title + 1, &inumgr, itype1, itype2, &itype3, &
	    itype4, &itype5, (ftnlen)1);

    return 0;
} /* quaplot2_ */






/* Subroutine */ int quaplot3_(integer *iw, doublereal *x, doublereal *y, 
	integer *n, integer *itype1, doublereal *x2, doublereal *y2, integer *
	n2, integer *itype2, doublereal *x3, doublereal *y3, integer *n3, 
	integer *itype3, char *title, ftnlen title_len)
{
    static integer n4, n5;
    static doublereal x4[1], y4[1], x5[1], y5[1];
    static integer itype4, itype5, inumgr;
    extern /* Subroutine */ int quaplo0_(integer *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);


    /* Parameter adjustments */
    --title;
    --y3;
    --x3;
    --y2;
    --x2;
    --y;
    --x;

    /* Function Body */
    inumgr = 3;

    quaplo0_(iw, &x[1], &y[1], &x2[1], &y2[1], &x3[1], &y3[1], x4, y4, x5, y5,
	     n, n2, n3, &n4, &n5, title + 1, &inumgr, itype1, itype2, itype3, 
	    &itype4, &itype5, (ftnlen)1);

    return 0;
} /* quaplot3_ */






/* Subroutine */ int quaplot4_(integer *iw, doublereal *x, doublereal *y, 
	integer *n, integer *itype1, doublereal *x2, doublereal *y2, integer *
	n2, integer *itype2, doublereal *x3, doublereal *y3, integer *n3, 
	integer *itype3, doublereal *x4, doublereal *y4, integer *n4, integer 
	*itype4, char *title, ftnlen title_len)
{
    static integer n5;
    static doublereal x5[1], y5[1];
    static integer itype5, inumgr;
    extern /* Subroutine */ int quaplo0_(integer *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);


    /* Parameter adjustments */
    --title;
    --y4;
    --x4;
    --y3;
    --x3;
    --y2;
    --x2;
    --y;
    --x;

    /* Function Body */
    inumgr = 4;

    quaplo0_(iw, &x[1], &y[1], &x2[1], &y2[1], &x3[1], &y3[1], &x4[1], &y4[1],
	     x5, y5, n, n2, n3, n4, &n5, title + 1, &inumgr, itype1, itype2, 
	    itype3, itype4, &itype5, (ftnlen)1);

    return 0;
} /* quaplot4_ */






/* Subroutine */ int quaplot5_(integer *iw, doublereal *x, doublereal *y, 
	integer *n, integer *itype1, doublereal *x2, doublereal *y2, integer *
	n2, integer *itype2, doublereal *x3, doublereal *y3, integer *n3, 
	integer *itype3, doublereal *x4, doublereal *y4, integer *n4, integer 
	*itype4, doublereal *x5, doublereal *y5, integer *n5, integer *itype5,
	 char *title, ftnlen title_len)
{
    static integer inumgr;
    extern /* Subroutine */ int quaplo0_(integer *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);


    /* Parameter adjustments */
    --title;
    --y5;
    --x5;
    --y4;
    --x4;
    --y3;
    --x3;
    --y2;
    --x2;
    --y;
    --x;

    /* Function Body */
    inumgr = 5;

    quaplo0_(iw, &x[1], &y[1], &x2[1], &y2[1], &x3[1], &y3[1], &x4[1], &y4[1],
	     &x5[1], &y5[1], n, n2, n3, n4, n5, title + 1, &inumgr, itype1, 
	    itype2, itype3, itype4, itype5, (ftnlen)1);

    return 0;
} /* quaplot5_ */






/* Subroutine */ int quaplo0_(integer *iw, doublereal *x, doublereal *y, 
	doublereal *x2, doublereal *y2, doublereal *x3, doublereal *y3, 
	doublereal *x4, doublereal *y4, doublereal *x5, doublereal *y5, 
	integer *n, integer *n2, integer *n3, integer *n4, integer *n5, char *
	title, integer *inumgr, integer *itype1, integer *itype2, integer *
	itype3, integer *itype4, integer *itype5, ftnlen title_len)
{
    /* Initialized data */

    static char gn[1*2] = "g" "n";
    static char blank[1] = " ";
    static char quo[1] = "\"";
    static char backslash[1] = "\\";
    static char ccc[1] = "c";

    /* Format strings */
    static char fmt_1100[] = "(i1)";
    static char fmt_1200[] = "(i2)";
    static char fmt_1300[] = "(i3)";
    static char fmt_1400[] = "(i4)";
    static char fmt_2000[] = "(1a8)";
    static char fmt_2250[] = "(\002   # set terminal postscript\002,/,\002  "
	    " # set output \"plot.ps\"\002,/,\002   # set size 0.76, 1.0 \002)"
	    ;
    static char fmt_2255[] = "(\002    set terminal postscript\002,/,\002   "
	    " set output \"plot.ps\"\002)";
    static char fmt_2270[] = "(\002  set title \002,80a1)";
    static char fmt_2280[] = "(\002   show title\002)";
    static char fmt_2350[] = "(2x,\002 set size 0.76, 1.0\002)";
    static char fmt_2400[] = "(i6)";
    static char fmt_2800[] = "(\002plot \002,\002[\002,e8.2,\002:\002,e8.2"
	    ",\002] \002,\002[\002,e8.2,\002:\002,e8.2,\002] \002,\002\"\002,"
	    "1a8,\002\" \002,\002notitle with dots\002)";
    static char fmt_2803[] = "(\002plot \002,\002[\002,e8.2,\002:\002,e8.2"
	    ",\002] \002,\002[\002,e8.2,\002:\002,e8.2,\002] \002,\002\"\002,"
	    "1a8,\002\" \002,\002notitle with points\002)";
    static char fmt_2805[] = "(\002plot \002,\002[\002,e8.2,\002:\002,e8.2"
	    ",\002] \002,\002[\002,e8.2,\002:\002,e8.2,\002] \002,\002\"\002,"
	    "1a8,\002\" \002,\002notitle with lines\002)";
    static char fmt_2830[] = "(\002plot \002,\002[\002,e8.2,\002:\002,e8.2"
	    ",\002] \002,\002[\002,e8.2,\002:\002,e8.2,\002] \002,\002\"\002,"
	    "1a8,\002\" \002,\002notitle with dots, \002,1a1)";
    static char fmt_2833[] = "(\002plot \002,\002[\002,e8.2,\002:\002,e8.2"
	    ",\002] \002,\002[\002,e8.2,\002:\002,e8.2,\002] \002,\002\"\002,"
	    "1a8,\002\" \002,\002notitle with points, \002,1a1)";
    static char fmt_2835[] = "(\002plot \002,\002[\002,e8.2,\002:\002,e8.2"
	    ",\002] \002,\002[\002,e8.2,\002:\002,e8.2,\002] \002,\002\"\002,"
	    "1a8,\002\" \002,\002notitle with lines, \002,1a1)";
    static char fmt_3000[] = "(2x,e11.5,2x,e11.5)";
    static char fmt_2850[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with dots\002)";
    static char fmt_2851[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with points\002)";
    static char fmt_2852[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with lines\002)";
    static char fmt_2855[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with dots, \002,1a1)";
    static char fmt_2856[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with points, \002,1a1)";
    static char fmt_2857[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with lines, \002,1a1)";
    static char fmt_2870[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with dots\002)";
    static char fmt_2871[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with points\002)";
    static char fmt_2872[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with lines\002)";
    static char fmt_2875[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with dots, \002,1a1)";
    static char fmt_2876[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with points, \002,1a1)";
    static char fmt_2877[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with lines, \002,1a1)";
    static char fmt_2890[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with dots\002)";
    static char fmt_2891[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with points\002)";
    static char fmt_2892[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with lines\002)";
    static char fmt_2895[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with dots, \002,1a1)";
    static char fmt_2896[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with points, \002,1a1)";
    static char fmt_2897[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with lines, \002,1a1)";
    static char fmt_2910[] = "(\002     \002,\002\"\002,1a8,\002\"\002,\002n"
	    "otitle  with dots\002)";
    static char fmt_2911[] = "(\002     \002,\002\"\002,1a8,\002\"\002,\002n"
	    "otitle  with points\002)";
    static char fmt_2912[] = "(\002     \002,\002\"\002,1a8,\002\"\002,\002n"
	    "otitle  with lines\002)";

    /* System generated locals */
    integer i__1;
    olist o__1;
    cllist cl__1;
    static char equiv_0[8], equiv_1[8], equiv_2[8], equiv_3[8];

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_rsfi(icilist *), e_rsfi(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer f_open(olist *), s_wsfe(cilist *), e_wsfe(void), f_clos(cllist *);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int quamesslen_(char *, integer *, char *, ftnlen,
	     ftnlen);
    static integer iun, iun2;
    static char line[1*82];
    static integer iunc, iun22;
    static doublereal size, xmin, ymin, xmax, ymax;
#define file1 (equiv_0)
#define file8 (equiv_0)
#define anum1 (equiv_1)
#define anum8 (equiv_1)
    static integer nchar;
    static char dummy[8];
    static doublereal xsize;
#define file1c (equiv_3)
    static doublereal ysize;
#define file8c (equiv_3)
#define anum1c (equiv_2)
#define anum8c (equiv_2)
    static doublereal xcenter, ycenter;

    /* Fortran I/O blocks */
    static icilist io___114 = { 0, dummy, 0, fmt_1100, 8, 1 };
    static icilist io___115 = { 0, dummy, 0, fmt_1200, 8, 1 };
    static icilist io___116 = { 0, dummy, 0, fmt_1300, 8, 1 };
    static icilist io___117 = { 0, dummy, 0, fmt_1400, 8, 1 };
    static icilist io___118 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___122 = { 0, 0, 0, fmt_2250, 0 };
    static cilist io___123 = { 0, 0, 0, fmt_2255, 0 };
    static cilist io___126 = { 0, 0, 0, fmt_2270, 0 };
    static cilist io___127 = { 0, 0, 0, fmt_2270, 0 };
    static cilist io___128 = { 0, 0, 0, fmt_2280, 0 };
    static cilist io___129 = { 0, 0, 0, fmt_2280, 0 };
    static cilist io___139 = { 0, 0, 0, fmt_2350, 0 };
    static icilist io___141 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___142 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___143 = { 0, 0, 0, fmt_2800, 0 };
    static cilist io___144 = { 0, 0, 0, fmt_2803, 0 };
    static cilist io___145 = { 0, 0, 0, fmt_2805, 0 };
    static cilist io___146 = { 0, 0, 0, fmt_2800, 0 };
    static cilist io___147 = { 0, 0, 0, fmt_2803, 0 };
    static cilist io___148 = { 0, 0, 0, fmt_2805, 0 };
    static cilist io___149 = { 0, 0, 0, fmt_2830, 0 };
    static cilist io___150 = { 0, 0, 0, fmt_2833, 0 };
    static cilist io___151 = { 0, 0, 0, fmt_2835, 0 };
    static cilist io___152 = { 0, 0, 0, fmt_2830, 0 };
    static cilist io___153 = { 0, 0, 0, fmt_2833, 0 };
    static cilist io___154 = { 0, 0, 0, fmt_2835, 0 };
    static cilist io___156 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___157 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___158 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___159 = { 0, 0, 0, fmt_2850, 0 };
    static cilist io___160 = { 0, 0, 0, fmt_2851, 0 };
    static cilist io___161 = { 0, 0, 0, fmt_2852, 0 };
    static cilist io___162 = { 0, 0, 0, fmt_2850, 0 };
    static cilist io___163 = { 0, 0, 0, fmt_2851, 0 };
    static cilist io___164 = { 0, 0, 0, fmt_2852, 0 };
    static cilist io___165 = { 0, 0, 0, fmt_2855, 0 };
    static cilist io___166 = { 0, 0, 0, fmt_2856, 0 };
    static cilist io___167 = { 0, 0, 0, fmt_2857, 0 };
    static cilist io___168 = { 0, 0, 0, fmt_2855, 0 };
    static cilist io___169 = { 0, 0, 0, fmt_2856, 0 };
    static cilist io___170 = { 0, 0, 0, fmt_2857, 0 };
    static cilist io___171 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___172 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___173 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___174 = { 0, 0, 0, fmt_2870, 0 };
    static cilist io___175 = { 0, 0, 0, fmt_2871, 0 };
    static cilist io___176 = { 0, 0, 0, fmt_2872, 0 };
    static cilist io___177 = { 0, 0, 0, fmt_2870, 0 };
    static cilist io___178 = { 0, 0, 0, fmt_2871, 0 };
    static cilist io___179 = { 0, 0, 0, fmt_2872, 0 };
    static cilist io___180 = { 0, 0, 0, fmt_2875, 0 };
    static cilist io___181 = { 0, 0, 0, fmt_2876, 0 };
    static cilist io___182 = { 0, 0, 0, fmt_2877, 0 };
    static cilist io___183 = { 0, 0, 0, fmt_2875, 0 };
    static cilist io___184 = { 0, 0, 0, fmt_2876, 0 };
    static cilist io___185 = { 0, 0, 0, fmt_2877, 0 };
    static cilist io___186 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___187 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___188 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___189 = { 0, 0, 0, fmt_2890, 0 };
    static cilist io___190 = { 0, 0, 0, fmt_2891, 0 };
    static cilist io___191 = { 0, 0, 0, fmt_2892, 0 };
    static cilist io___192 = { 0, 0, 0, fmt_2890, 0 };
    static cilist io___193 = { 0, 0, 0, fmt_2891, 0 };
    static cilist io___194 = { 0, 0, 0, fmt_2892, 0 };
    static cilist io___195 = { 0, 0, 0, fmt_2895, 0 };
    static cilist io___196 = { 0, 0, 0, fmt_2896, 0 };
    static cilist io___197 = { 0, 0, 0, fmt_2897, 0 };
    static cilist io___198 = { 0, 0, 0, fmt_2895, 0 };
    static cilist io___199 = { 0, 0, 0, fmt_2896, 0 };
    static cilist io___200 = { 0, 0, 0, fmt_2897, 0 };
    static cilist io___201 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___202 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___203 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___204 = { 0, 0, 0, fmt_2910, 0 };
    static cilist io___205 = { 0, 0, 0, fmt_2911, 0 };
    static cilist io___206 = { 0, 0, 0, fmt_2912, 0 };
    static cilist io___207 = { 0, 0, 0, fmt_2910, 0 };
    static cilist io___208 = { 0, 0, 0, fmt_2911, 0 };
    static cilist io___209 = { 0, 0, 0, fmt_2912, 0 };
    static cilist io___210 = { 0, 0, 0, fmt_3000, 0 };



    /* Parameter adjustments */
    --title;
    --y5;
    --x5;
    --y4;
    --x4;
    --y3;
    --x3;
    --y2;
    --x2;
    --y;
    --x;

    /* Function Body */

/*        convert the user-specified Fortran unit number to */
/*        character format */

    if (*iw >= 0 && *iw <= 9) {
	s_wsfi(&io___114);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 10 && *iw <= 99) {
	s_wsfi(&io___115);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 100 && *iw <= 999) {
	s_wsfi(&io___116);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 1000 && *iw <= 9999) {
	s_wsfi(&io___117);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

/* L2000: */
    s_rsfi(&io___118);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();
    s_copy(anum8c, anum8, (ftnlen)8, (ftnlen)8);

    if (*iw >= 0 && *iw <= 9) {
	*(unsigned char *)&anum1c[1] = *(unsigned char *)&ccc[0];
    }
    if (*iw >= 10 && *iw <= 99) {
	*(unsigned char *)&anum1c[2] = *(unsigned char *)&ccc[0];
    }
    if (*iw >= 100 && *iw <= 999) {
	*(unsigned char *)&anum1c[3] = *(unsigned char *)&ccc[0];
    }
    if (*iw >= 1000 && *iw <= 9999) {
	*(unsigned char *)&anum1c[4] = *(unsigned char *)&ccc[0];
    }

/*        construct the file name on which the Gnuplot instructions */
/*        are to be written */

    *(unsigned char *)&file1[0] = *(unsigned char *)&gn[0];
    *(unsigned char *)&file1[1] = *(unsigned char *)&gn[1];
    *(unsigned char *)&file1c[0] = *(unsigned char *)&gn[0];
    *(unsigned char *)&file1c[1] = *(unsigned char *)&gn[1];
    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
	*(unsigned char *)&file1c[i__ + 1] = *(unsigned char *)&anum1c[i__ - 
		1];
/* L2200: */
    }

/*        open the fortran file with the unit 87 and name file8 */

    iun = 87;
    o__1.oerr = 0;
    o__1.ounit = iun;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    iunc = 97;
    o__1.oerr = 0;
    o__1.ounit = iunc;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8c;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

/* c 2250 format('   # set terminal postscript',/, */
/* c     1    '   # set output "plot.ps"') */
/* c */
/* L2250: */

    io___122.ciunit = iun;
    s_wsfe(&io___122);
    e_wsfe();

/*        generate the title for the plot */

/* L2255: */

    io___123.ciunit = iunc;
    s_wsfe(&io___123);
    e_wsfe();
    *(unsigned char *)&line[0] = *(unsigned char *)&blank[0];
    *(unsigned char *)&line[1] = *(unsigned char *)&blank[0];
    *(unsigned char *)&line[2] = *(unsigned char *)&quo[0];

    quamesslen_(title + 1, &nchar, line + 3, (ftnlen)1, (ftnlen)1);

    *(unsigned char *)&line[nchar + 3] = *(unsigned char *)&quo[0];
/* L2270: */

    io___126.ciunit = iun;
    s_wsfe(&io___126);
    i__1 = nchar + 4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, line + (i__ - 1), (ftnlen)1);
    }
    e_wsfe();
    io___127.ciunit = iunc;
    s_wsfe(&io___127);
    i__1 = nchar + 4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, line + (i__ - 1), (ftnlen)1);
    }
    e_wsfe();

/* L2280: */
    io___128.ciunit = iun;
    s_wsfe(&io___128);
    e_wsfe();
    io___129.ciunit = iunc;
    s_wsfe(&io___129);
    e_wsfe();

/*        find the limits for both x and y */

    xmin = 1e30;
    ymin = 1e30;
    xmax = -1e20;
    ymax = -1e20;

    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (x[i__] < xmin) {
	    xmin = x[i__];
	}
	if (y[i__] < ymin) {
	    ymin = y[i__];
	}
	if (x[i__] > xmax) {
	    xmax = x[i__];
	}
	if (y[i__] > ymax) {
	    ymax = y[i__];
	}
/* L2300: */
    }

    if (*inumgr == 1) {
	goto L2345;
    }

    i__1 = *n2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (x2[i__] < xmin) {
	    xmin = x2[i__];
	}
	if (y2[i__] < ymin) {
	    ymin = y2[i__];
	}
	if (x2[i__] > xmax) {
	    xmax = x2[i__];
	}
	if (y2[i__] > ymax) {
	    ymax = y2[i__];
	}
/* L2310: */
    }

    if (*inumgr == 2) {
	goto L2345;
    }

    i__1 = *n3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (x3[i__] < xmin) {
	    xmin = x3[i__];
	}
	if (y3[i__] < ymin) {
	    ymin = y3[i__];
	}
	if (x3[i__] > xmax) {
	    xmax = x3[i__];
	}
	if (y3[i__] > ymax) {
	    ymax = y3[i__];
	}
/* L2320: */
    }

    if (*inumgr == 3) {
	goto L2345;
    }

    i__1 = *n4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (x4[i__] < xmin) {
	    xmin = x4[i__];
	}
	if (y4[i__] < ymin) {
	    ymin = y4[i__];
	}
	if (x4[i__] > xmax) {
	    xmax = x4[i__];
	}
	if (y4[i__] > ymax) {
	    ymax = y4[i__];
	}
/* L2330: */
    }

    if (*inumgr == 4) {
	goto L2345;
    }

    i__1 = *n5;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (x5[i__] < xmin) {
	    xmin = x5[i__];
	}
	if (y5[i__] < ymin) {
	    ymin = y5[i__];
	}
	if (x5[i__] > xmax) {
	    xmax = x5[i__];
	}
	if (y5[i__] > ymax) {
	    ymax = y5[i__];
	}
/* L2340: */
    }

L2345:

    xcenter = (xmin + xmax) / 2;
    ycenter = (ymax + ymin) / 2;

    xsize = xmax - xmin;
    ysize = ymax - ymin;
    size = xsize;
    if (ysize > size) {
	size = ysize;
    }
    size *= 1.2f;

    xmin = xcenter - size / 2;
    xmax = xcenter + size / 2;
    ymin = ycenter - size / 2;
    ymax = ycenter + size / 2;

/*        set the size of the stupid thing */

/* ccc 2350 format(2x,' set size 0.75,1.0') */
/* L2350: */
    io___139.ciunit = iunc;
    s_wsfe(&io___139);
    e_wsfe();

/*        write the instructions */

/* L2400: */
    iun2 = *iw + 100000;
    s_wsfi(&io___141);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___142);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2600: */
    }

/* L2800: */
/* L2803: */
/* L2805: */

    if (*inumgr == 1 && *itype1 == 1) {
	io___143.ciunit = iun;
	s_wsfe(&io___143);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 1 && *itype1 == 2) {
	io___144.ciunit = iun;
	s_wsfe(&io___144);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 1 && *itype1 == 3) {
	io___145.ciunit = iun;
	s_wsfe(&io___145);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }


    if (*inumgr == 1 && *itype1 == 1) {
	io___146.ciunit = iunc;
	s_wsfe(&io___146);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 1 && *itype1 == 2) {
	io___147.ciunit = iunc;
	s_wsfe(&io___147);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 1 && *itype1 == 3) {
	io___148.ciunit = iunc;
	s_wsfe(&io___148);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/* L2830: */

/* L2833: */

/* L2835: */

    if (*inumgr != 1 && *itype1 == 1) {
	io___149.ciunit = iun;
	s_wsfe(&io___149);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 1 && *itype1 == 2) {
	io___150.ciunit = iun;
	s_wsfe(&io___150);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 1 && *itype1 == 3) {
	io___151.ciunit = iun;
	s_wsfe(&io___151);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }
    if (*inumgr != 1 && *itype1 == 1) {
	io___152.ciunit = iunc;
	s_wsfe(&io___152);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 1 && *itype1 == 2) {
	io___153.ciunit = iunc;
	s_wsfe(&io___153);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 1 && *itype1 == 3) {
	io___154.ciunit = iunc;
	s_wsfe(&io___154);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

/*        write the first data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___156.ciunit = iun22;
    s_wsfe(&io___156);
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&x[i__], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the second data file */

    if (*inumgr == 1) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 1) {
	cl__1.cerr = 0;
	cl__1.cunit = iunc;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 1) {
	return 0;
    }

    iun2 = *iw + 200000;
    s_wsfi(&io___157);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___158);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2840: */
    }

/* L2850: */
/* L2851: */
/* L2852: */

    if (*inumgr == 2 && *itype2 == 1) {
	io___159.ciunit = iun;
	s_wsfe(&io___159);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 2 && *itype2 == 2) {
	io___160.ciunit = iun;
	s_wsfe(&io___160);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 2 && *itype2 == 3) {
	io___161.ciunit = iun;
	s_wsfe(&io___161);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }


    if (*inumgr == 2 && *itype2 == 1) {
	io___162.ciunit = iunc;
	s_wsfe(&io___162);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 2 && *itype2 == 2) {
	io___163.ciunit = iunc;
	s_wsfe(&io___163);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 2 && *itype2 == 3) {
	io___164.ciunit = iunc;
	s_wsfe(&io___164);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/* L2855: */
/* L2856: */
/* L2857: */

    if (*inumgr != 2 && *itype2 == 1) {
	io___165.ciunit = iun;
	s_wsfe(&io___165);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 2 && *itype2 == 2) {
	io___166.ciunit = iun;
	s_wsfe(&io___166);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 2 && *itype2 == 3) {
	io___167.ciunit = iun;
	s_wsfe(&io___167);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }


    if (*inumgr != 2 && *itype2 == 1) {
	io___168.ciunit = iunc;
	s_wsfe(&io___168);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 2 && *itype2 == 2) {
	io___169.ciunit = iunc;
	s_wsfe(&io___169);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 2 && *itype2 == 3) {
	io___170.ciunit = iunc;
	s_wsfe(&io___170);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

/*        write the second data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___171.ciunit = iun22;
    s_wsfe(&io___171);
    i__1 = *n2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&x2[i__], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y2[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the third data file */

    if (*inumgr == 2) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 2) {
	cl__1.cerr = 0;
	cl__1.cunit = iunc;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 2) {
	return 0;
    }

    iun2 = *iw + 300000;
    s_wsfi(&io___172);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___173);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2860: */
    }

/* L2870: */
/* L2871: */
/* L2872: */

    if (*inumgr == 3 && *itype3 == 1) {
	io___174.ciunit = iun;
	s_wsfe(&io___174);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 3 && *itype3 == 2) {
	io___175.ciunit = iun;
	s_wsfe(&io___175);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 3 && *itype3 == 3) {
	io___176.ciunit = iun;
	s_wsfe(&io___176);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }


    if (*inumgr == 3 && *itype3 == 1) {
	io___177.ciunit = iunc;
	s_wsfe(&io___177);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 3 && *itype3 == 2) {
	io___178.ciunit = iunc;
	s_wsfe(&io___178);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 3 && *itype3 == 3) {
	io___179.ciunit = iunc;
	s_wsfe(&io___179);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/* L2875: */
/* L2876: */
/* L2877: */

    if (*inumgr != 3 && *itype3 == 1) {
	io___180.ciunit = iun;
	s_wsfe(&io___180);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 3 && *itype3 == 2) {
	io___181.ciunit = iun;
	s_wsfe(&io___181);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 3 && *itype3 == 3) {
	io___182.ciunit = iun;
	s_wsfe(&io___182);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }


    if (*inumgr != 3 && *itype3 == 1) {
	io___183.ciunit = iunc;
	s_wsfe(&io___183);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 3 && *itype3 == 2) {
	io___184.ciunit = iunc;
	s_wsfe(&io___184);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 3 && *itype3 == 3) {
	io___185.ciunit = iunc;
	s_wsfe(&io___185);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

/*        write the third data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___186.ciunit = iun22;
    s_wsfe(&io___186);
    i__1 = *n3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&x3[i__], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y3[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the forth data file */

    if (*inumgr == 3) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 3) {
	cl__1.cerr = 0;
	cl__1.cunit = iunc;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 3) {
	return 0;
    }

    iun2 = *iw + 400000;
    s_wsfi(&io___187);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___188);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2880: */
    }

/* L2890: */
/* L2891: */
/* L2892: */

    if (*inumgr == 4 && *itype4 == 1) {
	io___189.ciunit = iun;
	s_wsfe(&io___189);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 4 && *itype4 == 2) {
	io___190.ciunit = iun;
	s_wsfe(&io___190);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 4 && *itype4 == 3) {
	io___191.ciunit = iun;
	s_wsfe(&io___191);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }


    if (*inumgr == 4 && *itype4 == 1) {
	io___192.ciunit = iunc;
	s_wsfe(&io___192);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 4 && *itype4 == 2) {
	io___193.ciunit = iunc;
	s_wsfe(&io___193);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 4 && *itype4 == 3) {
	io___194.ciunit = iunc;
	s_wsfe(&io___194);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/* L2895: */
/* L2896: */
/* L2897: */

    if (*inumgr != 4 && *itype4 == 1) {
	io___195.ciunit = iun;
	s_wsfe(&io___195);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 4 && *itype4 == 2) {
	io___196.ciunit = iun;
	s_wsfe(&io___196);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 4 && *itype4 == 3) {
	io___197.ciunit = iun;
	s_wsfe(&io___197);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }


    if (*inumgr != 4 && *itype4 == 1) {
	io___198.ciunit = iunc;
	s_wsfe(&io___198);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 4 && *itype4 == 2) {
	io___199.ciunit = iunc;
	s_wsfe(&io___199);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 4 && *itype4 == 3) {
	io___200.ciunit = iunc;
	s_wsfe(&io___200);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

/*        write the forth data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___201.ciunit = iun22;
    s_wsfe(&io___201);
    i__1 = *n4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&x4[i__], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y4[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the fifth data file */

    if (*inumgr == 4) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 4) {
	cl__1.cerr = 0;
	cl__1.cunit = iunc;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 4) {
	return 0;
    }

    iun2 = *iw + 500000;
    s_wsfi(&io___202);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___203);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2900: */
    }

/* L2910: */
/* L2911: */
/* L2912: */

    if (*itype5 == 1) {
	io___204.ciunit = iun;
	s_wsfe(&io___204);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*itype5 == 2) {
	io___205.ciunit = iun;
	s_wsfe(&io___205);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*itype5 == 3) {
	io___206.ciunit = iun;
	s_wsfe(&io___206);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*itype5 == 1) {
	io___207.ciunit = iunc;
	s_wsfe(&io___207);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*itype5 == 2) {
	io___208.ciunit = iunc;
	s_wsfe(&io___208);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*itype5 == 3) {
	io___209.ciunit = iunc;
	s_wsfe(&io___209);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/*        write the fifth data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);


    io___210.ciunit = iun22;
    s_wsfe(&io___210);
    i__1 = *n5;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&x5[i__], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y5[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = iun;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = iunc;
    cl__1.csta = 0;
    f_clos(&cl__1);

    return 0;
} /* quaplo0_ */

#undef anum8c
#undef anum1c
#undef file8c
#undef file1c
#undef anum8
#undef anum1
#undef file8
#undef file1







/* Subroutine */ int quagraph_(integer *iw, doublereal *x, doublereal *y, 
	integer *n, integer *itype1, char *title, ftnlen title_len)
{
    static integer n2, n3, n4, n5;
    static doublereal x2[1], y2[1], x3[1], y3[1], x4[1], y4[1], x5[1], y5[1];
    static integer itype2, itype3, itype4, itype5, inumgr;
    extern /* Subroutine */ int quagrap0_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);


    /* Parameter adjustments */
    --title;
    --y;
    --x;

    /* Function Body */
    inumgr = 1;

    quagrap0_(iw, &x[1], &y[1], x2, y2, x3, y3, x4, y4, x5, y5, n, &n2, &n3, &
	    n4, &n5, title + 1, &inumgr, itype1, &itype2, &itype3, &itype4, &
	    itype5, (ftnlen)1);

    return 0;
} /* quagraph_ */






/* Subroutine */ int quagraph2_(integer *iw, doublereal *x, doublereal *y, 
	integer *n, integer *itype1, doublereal *x2, doublereal *y2, integer *
	n2, integer *itype2, char *title, ftnlen title_len)
{
    static integer n3, n4, n5;
    static doublereal x3[1], y3[1], x4[1], y4[1], x5[1], y5[1];
    static integer itype3, itype4, itype5, inumgr;
    extern /* Subroutine */ int quagrap0_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);


    /* Parameter adjustments */
    --title;
    --y2;
    --x2;
    --y;
    --x;

    /* Function Body */
    inumgr = 2;

    quagrap0_(iw, &x[1], &y[1], &x2[1], &y2[1], x3, y3, x4, y4, x5, y5, n, n2,
	     &n3, &n4, &n5, title + 1, &inumgr, itype1, itype2, &itype3, &
	    itype4, &itype5, (ftnlen)1);

    return 0;
} /* quagraph2_ */






/* Subroutine */ int quagraph3_(integer *iw, doublereal *x, doublereal *y, 
	integer *n, integer *itype1, doublereal *x2, doublereal *y2, integer *
	n2, integer *itype2, doublereal *x3, doublereal *y3, integer *n3, 
	integer *itype3, char *title, ftnlen title_len)
{
    static integer n4, n5;
    static doublereal x4[1], y4[1], x5[1], y5[1];
    static integer itype4, itype5, inumgr;
    extern /* Subroutine */ int quagrap0_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);


    /* Parameter adjustments */
    --title;
    --y3;
    --x3;
    --y2;
    --x2;
    --y;
    --x;

    /* Function Body */
    inumgr = 3;

    quagrap0_(iw, &x[1], &y[1], &x2[1], &y2[1], &x3[1], &y3[1], x4, y4, x5, 
	    y5, n, n2, n3, &n4, &n5, title + 1, &inumgr, itype1, itype2, 
	    itype3, &itype4, &itype5, (ftnlen)1);

    return 0;
} /* quagraph3_ */






/* Subroutine */ int quagraph4_(integer *iw, doublereal *x, doublereal *y, 
	integer *n, integer *itype1, doublereal *x2, doublereal *y2, integer *
	n2, integer *itype2, doublereal *x3, doublereal *y3, integer *n3, 
	integer *itype3, doublereal *x4, doublereal *y4, integer *n4, integer 
	*itype4, char *title, ftnlen title_len)
{
    static integer n5;
    static doublereal x5[1], y5[1];
    static integer itype5, inumgr;
    extern /* Subroutine */ int quagrap0_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);


    /* Parameter adjustments */
    --title;
    --y4;
    --x4;
    --y3;
    --x3;
    --y2;
    --x2;
    --y;
    --x;

    /* Function Body */
    inumgr = 4;

    quagrap0_(iw, &x[1], &y[1], &x2[1], &y2[1], &x3[1], &y3[1], &x4[1], &y4[1]
	    , x5, y5, n, n2, n3, n4, &n5, title + 1, &inumgr, itype1, itype2, 
	    itype3, itype4, &itype5, (ftnlen)1);

    return 0;
} /* quagraph4_ */






/* Subroutine */ int quagraph5_(integer *iw, doublereal *x, doublereal *y, 
	integer *n, integer *itype1, doublereal *x2, doublereal *y2, integer *
	n2, integer *itype2, doublereal *x3, doublereal *y3, integer *n3, 
	integer *itype3, doublereal *x4, doublereal *y4, integer *n4, integer 
	*itype4, doublereal *x5, doublereal *y5, integer *n5, integer *itype5,
	 char *title, ftnlen title_len)
{
    static integer inumgr;
    extern /* Subroutine */ int quagrap0_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);


    /* Parameter adjustments */
    --title;
    --y5;
    --x5;
    --y4;
    --x4;
    --y3;
    --x3;
    --y2;
    --x2;
    --y;
    --x;

    /* Function Body */
    inumgr = 5;

    quagrap0_(iw, &x[1], &y[1], &x2[1], &y2[1], &x3[1], &y3[1], &x4[1], &y4[1]
	    , &x5[1], &y5[1], n, n2, n3, n4, n5, title + 1, &inumgr, itype1, 
	    itype2, itype3, itype4, itype5, (ftnlen)1);

    return 0;
} /* quagraph5_ */






/* Subroutine */ int quagrap0_(integer *iw, doublereal *x, doublereal *y, 
	doublereal *x2, doublereal *y2, doublereal *x3, doublereal *y3, 
	doublereal *x4, doublereal *y4, doublereal *x5, doublereal *y5, 
	integer *n, integer *n2, integer *n3, integer *n4, integer *n5, char *
	title, integer *inumgr, integer *itype1, integer *itype2, integer *
	itype3, integer *itype4, integer *itype5, ftnlen title_len)
{
    /* Initialized data */

    static char gn[1*2] = "g" "n";
    static char blank[1] = " ";
    static char quo[1] = "\"";
    static char backslash[1] = "\\";
    static char ccc[1] = "c";

    /* Format strings */
    static char fmt_1100[] = "(i1)";
    static char fmt_1200[] = "(i2)";
    static char fmt_1300[] = "(i3)";
    static char fmt_1400[] = "(i4)";
    static char fmt_2000[] = "(1a8)";
    static char fmt_2250[] = "(\002   # set terminal postscript\002,/,\002  "
	    " # set output \"plot.ps\"\002,/,\002   # set size 0.76, 1.0 \002)"
	    ;
    static char fmt_2255[] = "(\002    set terminal postscript\002,/,\002   "
	    " set output \"plot.ps\"\002)";
    static char fmt_2300[] = "(\002  set title \002,80a1)";
    static char fmt_2350[] = "(\002   show title\002)";
    static char fmt_2400[] = "(i6)";
    static char fmt_2800[] = "(\002plot \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots\002)";
    static char fmt_2803[] = "(\002plot \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points\002)";
    static char fmt_2805[] = "(\002plot \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines\002)";
    static char fmt_2830[] = "(\002plot \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots, \002,1a1)";
    static char fmt_2831[] = "(\002plot \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points, \002,1a1)";
    static char fmt_2832[] = "(\002plot \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines, \002,1a1)";
    static char fmt_3000[] = "(2x,e11.5,2x,e11.5)";
    static char fmt_2850[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots\002)";
    static char fmt_2851[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points\002)";
    static char fmt_2852[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines\002)";
    static char fmt_2855[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots, \002,1a1)";
    static char fmt_2856[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points, \002,1a1)";
    static char fmt_2857[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines, \002,1a1)";
    static char fmt_2870[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots\002)";
    static char fmt_2871[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points\002)";
    static char fmt_2872[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines\002)";
    static char fmt_2875[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots, \002,1a1)";
    static char fmt_2876[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points, \002,1a1)";
    static char fmt_2877[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines, \002,1a1)";
    static char fmt_2890[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots\002)";
    static char fmt_2891[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points\002)";
    static char fmt_2892[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines\002)";
    static char fmt_2895[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots, \002,1a1)";
    static char fmt_2896[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points, \002,1a1)";
    static char fmt_2897[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines, \002,1a1)";
    static char fmt_2910[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots\002)";
    static char fmt_2911[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points\002)";
    static char fmt_2912[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines\002)";

    /* System generated locals */
    integer i__1;
    olist o__1;
    cllist cl__1;
    static char equiv_0[8], equiv_1[8], equiv_2[8], equiv_3[8];

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_rsfi(icilist *), e_rsfi(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer f_open(olist *), s_wsfe(cilist *), e_wsfe(void), f_clos(cllist *);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int quamesslen_(char *, integer *, char *, ftnlen,
	     ftnlen);
    static integer iun, iun2;
    static char line[1*82];
    static integer iunc, iun22;
#define file1 (equiv_0)
#define file8 (equiv_0)
#define anum1 (equiv_1)
#define anum8 (equiv_1)
    static integer nchar;
    static char dummy[8];
#define file1c (equiv_3)
#define file8c (equiv_3)
#define anum1c (equiv_2)
#define anum8c (equiv_2)

    /* Fortran I/O blocks */
    static icilist io___270 = { 0, dummy, 0, fmt_1100, 8, 1 };
    static icilist io___271 = { 0, dummy, 0, fmt_1200, 8, 1 };
    static icilist io___272 = { 0, dummy, 0, fmt_1300, 8, 1 };
    static icilist io___273 = { 0, dummy, 0, fmt_1400, 8, 1 };
    static icilist io___274 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___278 = { 0, 0, 0, fmt_2250, 0 };
    static cilist io___279 = { 0, 0, 0, fmt_2255, 0 };
    static cilist io___282 = { 0, 0, 0, fmt_2300, 0 };
    static cilist io___283 = { 0, 0, 0, fmt_2300, 0 };
    static cilist io___284 = { 0, 0, 0, fmt_2350, 0 };
    static cilist io___285 = { 0, 0, 0, fmt_2350, 0 };
    static icilist io___287 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___288 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___289 = { 0, 0, 0, fmt_2800, 0 };
    static cilist io___290 = { 0, 0, 0, fmt_2800, 0 };
    static cilist io___291 = { 0, 0, 0, fmt_2803, 0 };
    static cilist io___292 = { 0, 0, 0, fmt_2803, 0 };
    static cilist io___293 = { 0, 0, 0, fmt_2805, 0 };
    static cilist io___294 = { 0, 0, 0, fmt_2805, 0 };
    static cilist io___295 = { 0, 0, 0, fmt_2830, 0 };
    static cilist io___296 = { 0, 0, 0, fmt_2830, 0 };
    static cilist io___297 = { 0, 0, 0, fmt_2831, 0 };
    static cilist io___298 = { 0, 0, 0, fmt_2831, 0 };
    static cilist io___299 = { 0, 0, 0, fmt_2832, 0 };
    static cilist io___300 = { 0, 0, 0, fmt_2832, 0 };
    static cilist io___302 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___303 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___304 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___305 = { 0, 0, 0, fmt_2850, 0 };
    static cilist io___306 = { 0, 0, 0, fmt_2850, 0 };
    static cilist io___307 = { 0, 0, 0, fmt_2851, 0 };
    static cilist io___308 = { 0, 0, 0, fmt_2851, 0 };
    static cilist io___309 = { 0, 0, 0, fmt_2852, 0 };
    static cilist io___310 = { 0, 0, 0, fmt_2852, 0 };
    static cilist io___311 = { 0, 0, 0, fmt_2855, 0 };
    static cilist io___312 = { 0, 0, 0, fmt_2855, 0 };
    static cilist io___313 = { 0, 0, 0, fmt_2856, 0 };
    static cilist io___314 = { 0, 0, 0, fmt_2856, 0 };
    static cilist io___315 = { 0, 0, 0, fmt_2857, 0 };
    static cilist io___316 = { 0, 0, 0, fmt_2857, 0 };
    static cilist io___317 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___318 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___319 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___320 = { 0, 0, 0, fmt_2870, 0 };
    static cilist io___321 = { 0, 0, 0, fmt_2870, 0 };
    static cilist io___322 = { 0, 0, 0, fmt_2871, 0 };
    static cilist io___323 = { 0, 0, 0, fmt_2871, 0 };
    static cilist io___324 = { 0, 0, 0, fmt_2872, 0 };
    static cilist io___325 = { 0, 0, 0, fmt_2872, 0 };
    static cilist io___326 = { 0, 0, 0, fmt_2875, 0 };
    static cilist io___327 = { 0, 0, 0, fmt_2875, 0 };
    static cilist io___328 = { 0, 0, 0, fmt_2876, 0 };
    static cilist io___329 = { 0, 0, 0, fmt_2876, 0 };
    static cilist io___330 = { 0, 0, 0, fmt_2877, 0 };
    static cilist io___331 = { 0, 0, 0, fmt_2877, 0 };
    static cilist io___332 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___333 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___334 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___335 = { 0, 0, 0, fmt_2890, 0 };
    static cilist io___336 = { 0, 0, 0, fmt_2890, 0 };
    static cilist io___337 = { 0, 0, 0, fmt_2891, 0 };
    static cilist io___338 = { 0, 0, 0, fmt_2891, 0 };
    static cilist io___339 = { 0, 0, 0, fmt_2892, 0 };
    static cilist io___340 = { 0, 0, 0, fmt_2892, 0 };
    static cilist io___341 = { 0, 0, 0, fmt_2895, 0 };
    static cilist io___342 = { 0, 0, 0, fmt_2895, 0 };
    static cilist io___343 = { 0, 0, 0, fmt_2896, 0 };
    static cilist io___344 = { 0, 0, 0, fmt_2896, 0 };
    static cilist io___345 = { 0, 0, 0, fmt_2897, 0 };
    static cilist io___346 = { 0, 0, 0, fmt_2897, 0 };
    static cilist io___347 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___348 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___349 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___350 = { 0, 0, 0, fmt_2910, 0 };
    static cilist io___351 = { 0, 0, 0, fmt_2911, 0 };
    static cilist io___352 = { 0, 0, 0, fmt_2912, 0 };
    static cilist io___353 = { 0, 0, 0, fmt_2910, 0 };
    static cilist io___354 = { 0, 0, 0, fmt_2911, 0 };
    static cilist io___355 = { 0, 0, 0, fmt_2912, 0 };
    static cilist io___356 = { 0, 0, 0, fmt_3000, 0 };



    /* Parameter adjustments */
    --title;
    --y5;
    --x5;
    --y4;
    --x4;
    --y3;
    --x3;
    --y2;
    --x2;
    --y;
    --x;

    /* Function Body */

/*        convert the user-specified Fortran unit number to */
/*        character format */

    if (*iw >= 0 && *iw <= 9) {
	s_wsfi(&io___270);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 10 && *iw <= 99) {
	s_wsfi(&io___271);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 100 && *iw <= 999) {
	s_wsfi(&io___272);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 1000 && *iw <= 9999) {
	s_wsfi(&io___273);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

/* L2000: */
    s_rsfi(&io___274);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();
    s_copy(anum8c, anum8, (ftnlen)8, (ftnlen)8);

    if (*iw >= 0 && *iw <= 9) {
	*(unsigned char *)&anum1c[1] = *(unsigned char *)&ccc[0];
    }
    if (*iw >= 10 && *iw <= 99) {
	*(unsigned char *)&anum1c[2] = *(unsigned char *)&ccc[0];
    }
    if (*iw >= 100 && *iw <= 999) {
	*(unsigned char *)&anum1c[3] = *(unsigned char *)&ccc[0];
    }
    if (*iw >= 1000 && *iw <= 9999) {
	*(unsigned char *)&anum1c[4] = *(unsigned char *)&ccc[0];
    }

/*        construct the file name on which the Gnuplot instructions */
/*        are to be written */

    *(unsigned char *)&file1[0] = *(unsigned char *)&gn[0];
    *(unsigned char *)&file1[1] = *(unsigned char *)&gn[1];
    *(unsigned char *)&file1c[0] = *(unsigned char *)&gn[0];
    *(unsigned char *)&file1c[1] = *(unsigned char *)&gn[1];
    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
	*(unsigned char *)&file1c[i__ + 1] = *(unsigned char *)&anum1c[i__ - 
		1];
/* L2200: */
    }

/*        open the fortran file with the unit 87 and name file8 */

    iun = 87;
    o__1.oerr = 0;
    o__1.ounit = iun;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    iunc = 97;
    o__1.oerr = 0;
    o__1.ounit = iunc;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8c;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

/* L2250: */

/* L2255: */

    io___278.ciunit = iun;
    s_wsfe(&io___278);
    e_wsfe();
    io___279.ciunit = iunc;
    s_wsfe(&io___279);
    e_wsfe();

/*        generate the title for the plot */

    *(unsigned char *)&line[0] = *(unsigned char *)&blank[0];
    *(unsigned char *)&line[1] = *(unsigned char *)&blank[0];
    *(unsigned char *)&line[2] = *(unsigned char *)&quo[0];

    quamesslen_(title + 1, &nchar, line + 3, (ftnlen)1, (ftnlen)1);

    *(unsigned char *)&line[nchar + 3] = *(unsigned char *)&quo[0];
/* L2300: */
    io___282.ciunit = iun;
    s_wsfe(&io___282);
    i__1 = nchar + 4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, line + (i__ - 1), (ftnlen)1);
    }
    e_wsfe();
    io___283.ciunit = iunc;
    s_wsfe(&io___283);
    i__1 = nchar + 4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, line + (i__ - 1), (ftnlen)1);
    }
    e_wsfe();

/* L2350: */
    io___284.ciunit = iun;
    s_wsfe(&io___284);
    e_wsfe();
    io___285.ciunit = iunc;
    s_wsfe(&io___285);
    e_wsfe();

/*        write the instructions */

/* L2400: */
    iun2 = *iw + 100000;
    s_wsfi(&io___287);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___288);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2600: */
    }

/* L2800: */
/* L2803: */
/* L2805: */

    if (*inumgr == 1 && *itype1 == 1) {
	io___289.ciunit = iun;
	s_wsfe(&io___289);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*inumgr == 1 && *itype1 == 1) {
	io___290.ciunit = iunc;
	s_wsfe(&io___290);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 1 && *itype1 == 2) {
	io___291.ciunit = iun;
	s_wsfe(&io___291);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*inumgr == 1 && *itype1 == 2) {
	io___292.ciunit = iunc;
	s_wsfe(&io___292);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 1 && *itype1 == 3) {
	io___293.ciunit = iun;
	s_wsfe(&io___293);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*inumgr == 1 && *itype1 == 3) {
	io___294.ciunit = iunc;
	s_wsfe(&io___294);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/* L2830: */
/* L2831: */
/* L2832: */

    if (*inumgr != 1 && *itype1 == 1) {
	io___295.ciunit = iun;
	s_wsfe(&io___295);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }
    if (*inumgr != 1 && *itype1 == 1) {
	io___296.ciunit = iunc;
	s_wsfe(&io___296);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 1 && *itype1 == 2) {
	io___297.ciunit = iun;
	s_wsfe(&io___297);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }
    if (*inumgr != 1 && *itype1 == 2) {
	io___298.ciunit = iunc;
	s_wsfe(&io___298);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 1 && *itype1 == 3) {
	io___299.ciunit = iun;
	s_wsfe(&io___299);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }
    if (*inumgr != 1 && *itype1 == 3) {
	io___300.ciunit = iunc;
	s_wsfe(&io___300);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

/*        write the first data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___302.ciunit = iun22;
    s_wsfe(&io___302);
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&x[i__], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the second data file */

    if (*inumgr == 1) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 1) {
	cl__1.cerr = 0;
	cl__1.cunit = iunc;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 1) {
	return 0;
    }

    iun2 = *iw + 200000;
    s_wsfi(&io___303);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___304);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2840: */
    }

/* L2850: */
/* L2851: */
/* L2852: */

    if (*inumgr == 2 && *itype2 == 1) {
	io___305.ciunit = iun;
	s_wsfe(&io___305);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*inumgr == 2 && *itype2 == 1) {
	io___306.ciunit = iunc;
	s_wsfe(&io___306);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 2 && *itype2 == 2) {
	io___307.ciunit = iun;
	s_wsfe(&io___307);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*inumgr == 2 && *itype2 == 2) {
	io___308.ciunit = iunc;
	s_wsfe(&io___308);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 2 && *itype2 == 3) {
	io___309.ciunit = iun;
	s_wsfe(&io___309);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*inumgr == 2 && *itype2 == 3) {
	io___310.ciunit = iunc;
	s_wsfe(&io___310);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }


    if (*inumgr != 2 && *itype2 == 1) {
	io___311.ciunit = iun;
	s_wsfe(&io___311);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }
    if (*inumgr != 2 && *itype2 == 1) {
	io___312.ciunit = iunc;
	s_wsfe(&io___312);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 2 && *itype2 == 2) {
	io___313.ciunit = iun;
	s_wsfe(&io___313);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }
    if (*inumgr != 2 && *itype2 == 2) {
	io___314.ciunit = iunc;
	s_wsfe(&io___314);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 2 && *itype2 == 3) {
	io___315.ciunit = iun;
	s_wsfe(&io___315);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }
    if (*inumgr != 2 && *itype2 == 3) {
	io___316.ciunit = iunc;
	s_wsfe(&io___316);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }


/*        write the second data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___317.ciunit = iun22;
    s_wsfe(&io___317);
    i__1 = *n2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&x2[i__], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y2[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the third data file */

    if (*inumgr == 2) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 2) {
	cl__1.cerr = 0;
	cl__1.cunit = iunc;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 2) {
	return 0;
    }

    iun2 = *iw + 300000;
    s_wsfi(&io___318);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___319);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2860: */
    }

/* L2870: */
/* L2871: */
/* L2872: */

    if (*inumgr == 3 && *itype3 == 1) {
	io___320.ciunit = iun;
	s_wsfe(&io___320);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*inumgr == 3 && *itype3 == 1) {
	io___321.ciunit = iunc;
	s_wsfe(&io___321);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 3 && *itype3 == 2) {
	io___322.ciunit = iun;
	s_wsfe(&io___322);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*inumgr == 3 && *itype3 == 2) {
	io___323.ciunit = iunc;
	s_wsfe(&io___323);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 3 && *itype3 == 3) {
	io___324.ciunit = iun;
	s_wsfe(&io___324);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*inumgr == 3 && *itype3 == 3) {
	io___325.ciunit = iunc;
	s_wsfe(&io___325);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }


    if (*inumgr != 3 && *itype3 == 1) {
	io___326.ciunit = iun;
	s_wsfe(&io___326);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }
    if (*inumgr != 3 && *itype3 == 1) {
	io___327.ciunit = iunc;
	s_wsfe(&io___327);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 3 && *itype3 == 2) {
	io___328.ciunit = iun;
	s_wsfe(&io___328);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }
    if (*inumgr != 3 && *itype3 == 2) {
	io___329.ciunit = iunc;
	s_wsfe(&io___329);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 3 && *itype3 == 3) {
	io___330.ciunit = iun;
	s_wsfe(&io___330);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }
    if (*inumgr != 3 && *itype3 == 3) {
	io___331.ciunit = iunc;
	s_wsfe(&io___331);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }


/*        write the third data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___332.ciunit = iun22;
    s_wsfe(&io___332);
    i__1 = *n3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&x3[i__], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y3[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the forth data file */

    if (*inumgr == 3) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 3) {
	cl__1.cerr = 0;
	cl__1.cunit = iunc;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 3) {
	return 0;
    }

    iun2 = *iw + 400000;
    s_wsfi(&io___333);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___334);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2880: */
    }

/* L2890: */
/* L2891: */
/* L2892: */

    if (*inumgr == 4 && *itype4 == 1) {
	io___335.ciunit = iun;
	s_wsfe(&io___335);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*inumgr == 4 && *itype4 == 1) {
	io___336.ciunit = iunc;
	s_wsfe(&io___336);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 4 && *itype4 == 2) {
	io___337.ciunit = iun;
	s_wsfe(&io___337);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*inumgr == 4 && *itype4 == 2) {
	io___338.ciunit = iunc;
	s_wsfe(&io___338);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 4 && *itype4 == 3) {
	io___339.ciunit = iun;
	s_wsfe(&io___339);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*inumgr == 4 && *itype4 == 3) {
	io___340.ciunit = iunc;
	s_wsfe(&io___340);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }


    if (*inumgr != 4 && *itype4 == 1) {
	io___341.ciunit = iun;
	s_wsfe(&io___341);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }
    if (*inumgr != 4 && *itype4 == 1) {
	io___342.ciunit = iunc;
	s_wsfe(&io___342);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 4 && *itype4 == 2) {
	io___343.ciunit = iun;
	s_wsfe(&io___343);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }
    if (*inumgr != 4 && *itype4 == 2) {
	io___344.ciunit = iunc;
	s_wsfe(&io___344);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 4 && *itype4 == 3) {
	io___345.ciunit = iun;
	s_wsfe(&io___345);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }
    if (*inumgr != 4 && *itype4 == 3) {
	io___346.ciunit = iunc;
	s_wsfe(&io___346);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }


/*        write the forth data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___347.ciunit = iun22;
    s_wsfe(&io___347);
    i__1 = *n4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&x4[i__], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y4[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the fifth data file */

    if (*inumgr == 4) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 4) {
	cl__1.cerr = 0;
	cl__1.cunit = iunc;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 4) {
	return 0;
    }

    iun2 = *iw + 500000;
    s_wsfi(&io___348);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___349);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2900: */
    }

/* L2910: */
/* L2911: */
/* L2912: */

    if (*itype5 == 1) {
	io___350.ciunit = iun;
	s_wsfe(&io___350);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*itype5 == 2) {
	io___351.ciunit = iun;
	s_wsfe(&io___351);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*itype5 == 3) {
	io___352.ciunit = iun;
	s_wsfe(&io___352);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*itype5 == 1) {
	io___353.ciunit = iunc;
	s_wsfe(&io___353);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*itype5 == 2) {
	io___354.ciunit = iunc;
	s_wsfe(&io___354);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*itype5 == 3) {
	io___355.ciunit = iunc;
	s_wsfe(&io___355);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/*        write the fifth data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);


    io___356.ciunit = iun22;
    s_wsfe(&io___356);
    i__1 = *n5;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&x5[i__], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&y5[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = iun;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = iunc;
    cl__1.csta = 0;
    f_clos(&cl__1);

    return 0;
} /* quagrap0_ */

#undef anum8c
#undef anum1c
#undef file8c
#undef file1c
#undef anum8
#undef anum1
#undef file8
#undef file1







/* Subroutine */ int zquaplot_(integer *iw, doublereal *z__, integer *n, 
	integer *itype1, char *title, ftnlen title_len)
{
    extern /* Subroutine */ int zquaplo0_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, integer *,
	     integer *, integer *, integer *, char *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, ftnlen);
    static integer n2, n3, n4, n5;
    static doublereal z2[2]	/* was [2][1] */, z3[2]	/* was [2][1] */, z4[
	    2]	/* was [2][1] */, z5[2]	/* was [2][1] */;
    static integer itype2, itype3, itype4, itype5, inumgr;


    /* Parameter adjustments */
    --title;
    z__ -= 3;

    /* Function Body */
    inumgr = 1;

    zquaplo0_(iw, &z__[3], z2, z3, z4, z5, n, &n2, &n3, &n4, &n5, title + 1, &
	    inumgr, itype1, &itype2, &itype3, &itype4, &itype5, (ftnlen)1);

    return 0;
} /* zquaplot_ */






/* Subroutine */ int zquaplot2_(integer *iw, doublereal *z__, integer *n, 
	integer *itype1, doublereal *z2, integer *n2, integer *itype2, char *
	title, ftnlen title_len)
{
    extern /* Subroutine */ int zquaplo0_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, integer *,
	     integer *, integer *, integer *, char *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, ftnlen);
    static integer n3, n4, n5;
    static doublereal z3[2]	/* was [2][1] */, z4[2]	/* was [2][1] */, z5[
	    2]	/* was [2][1] */;
    static integer itype3, itype4, itype5, inumgr;


    /* Parameter adjustments */
    --title;
    z2 -= 3;
    z__ -= 3;

    /* Function Body */
    inumgr = 2;

    zquaplo0_(iw, &z__[3], &z2[3], z3, z4, z5, n, n2, &n3, &n4, &n5, title + 
	    1, &inumgr, itype1, itype2, &itype3, &itype4, &itype5, (ftnlen)1);

    return 0;
} /* zquaplot2_ */






/* Subroutine */ int zquaplot3_(integer *iw, doublereal *z__, integer *n, 
	integer *itype1, doublereal *z2, integer *n2, integer *itype2, 
	doublereal *z3, integer *n3, integer *itype3, char *title, ftnlen 
	title_len)
{
    extern /* Subroutine */ int zquaplo0_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, integer *,
	     integer *, integer *, integer *, char *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, ftnlen);
    static integer n4, n5;
    static doublereal z4[2]	/* was [2][1] */, z5[2]	/* was [2][1] */;
    static integer itype4, itype5, inumgr;


    /* Parameter adjustments */
    --title;
    z3 -= 3;
    z2 -= 3;
    z__ -= 3;

    /* Function Body */
    inumgr = 3;

    zquaplo0_(iw, &z__[3], &z2[3], &z3[3], z4, z5, n, n2, n3, &n4, &n5, title 
	    + 1, &inumgr, itype1, itype2, itype3, &itype4, &itype5, (ftnlen)1)
	    ;

    return 0;
} /* zquaplot3_ */






/* Subroutine */ int zquaplot4_(integer *iw, doublereal *z__, integer *n, 
	integer *itype1, doublereal *z2, integer *n2, integer *itype2, 
	doublereal *z3, integer *n3, integer *itype3, doublereal *z4, integer 
	*n4, integer *itype4, char *title, ftnlen title_len)
{
    extern /* Subroutine */ int zquaplo0_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, integer *,
	     integer *, integer *, integer *, char *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, ftnlen);
    static integer n5;
    static doublereal z5[2]	/* was [2][1] */;
    static integer itype5, inumgr;


    /* Parameter adjustments */
    --title;
    z4 -= 3;
    z3 -= 3;
    z2 -= 3;
    z__ -= 3;

    /* Function Body */
    inumgr = 4;

    zquaplo0_(iw, &z__[3], &z2[3], &z3[3], &z4[3], z5, n, n2, n3, n4, &n5, 
	    title + 1, &inumgr, itype1, itype2, itype3, itype4, &itype5, (
	    ftnlen)1);

    return 0;
} /* zquaplot4_ */






/* Subroutine */ int zquaplot5_(integer *iw, doublereal *z__, integer *n, 
	integer *itype1, doublereal *z2, integer *n2, integer *itype2, 
	doublereal *z3, integer *n3, integer *itype3, doublereal *z4, integer 
	*n4, integer *itype4, doublereal *z5, integer *n5, integer *itype5, 
	char *title, ftnlen title_len)
{
    extern /* Subroutine */ int zquaplo0_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, integer *,
	     integer *, integer *, integer *, char *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, ftnlen);
    static integer inumgr;


    /* Parameter adjustments */
    --title;
    z5 -= 3;
    z4 -= 3;
    z3 -= 3;
    z2 -= 3;
    z__ -= 3;

    /* Function Body */
    inumgr = 5;

    zquaplo0_(iw, &z__[3], &z2[3], &z3[3], &z4[3], &z5[3], n, n2, n3, n4, n5, 
	    title + 1, &inumgr, itype1, itype2, itype3, itype4, itype5, (
	    ftnlen)1);

    return 0;
} /* zquaplot5_ */






/* Subroutine */ int zquaplo0_(integer *iw, doublereal *z__, doublereal *z2, 
	doublereal *z3, doublereal *z4, doublereal *z5, integer *n, integer *
	n2, integer *n3, integer *n4, integer *n5, char *title, integer *
	inumgr, integer *itype1, integer *itype2, integer *itype3, integer *
	itype4, integer *itype5, ftnlen title_len)
{
    /* Initialized data */

    static char gn[1*2] = "g" "n";
    static char blank[1] = " ";
    static char quo[1] = "\"";
    static char backslash[1] = "\\";

    /* Format strings */
    static char fmt_1100[] = "(i1)";
    static char fmt_1200[] = "(i2)";
    static char fmt_1300[] = "(i3)";
    static char fmt_1400[] = "(i4)";
    static char fmt_2000[] = "(1a8)";
    static char fmt_2250[] = "(\002   # set terminal postscript\002,/,\002  "
	    " # set output \"plot.ps\"\002)";
    static char fmt_2270[] = "(\002  set title \002,80a1)";
    static char fmt_2280[] = "(\002   show title\002)";
    static char fmt_2350[] = "(2x,\002 set size 1.0, 1.0\002)";
    static char fmt_2400[] = "(i6)";
    static char fmt_2800[] = "(\002plot \002,\002[\002,e8.2,\002:\002,e8.2"
	    ",\002] \002,\002[\002,e8.2,\002:\002,e8.2,\002] \002,\002\"\002,"
	    "1a8,\002\" \002,\002notitle with dots\002)";
    static char fmt_2803[] = "(\002plot \002,\002[\002,e8.2,\002:\002,e8.2"
	    ",\002] \002,\002[\002,e8.2,\002:\002,e8.2,\002] \002,\002\"\002,"
	    "1a8,\002\" \002,\002notitle with points\002)";
    static char fmt_2805[] = "(\002plot \002,\002[\002,e8.2,\002:\002,e8.2"
	    ",\002] \002,\002[\002,e8.2,\002:\002,e8.2,\002] \002,\002\"\002,"
	    "1a8,\002\" \002,\002notitle with lines\002)";
    static char fmt_2830[] = "(\002plot \002,\002[\002,e8.2,\002:\002,e8.2"
	    ",\002] \002,\002[\002,e8.2,\002:\002,e8.2,\002] \002,\002\"\002,"
	    "1a8,\002\" \002,\002notitle with dots, \002,1a1)";
    static char fmt_2833[] = "(\002plot \002,\002[\002,e8.2,\002:\002,e8.2"
	    ",\002] \002,\002[\002,e8.2,\002:\002,e8.2,\002] \002,\002\"\002,"
	    "1a8,\002\" \002,\002notitle with points, \002,1a1)";
    static char fmt_2835[] = "(\002plot \002,\002[\002,e8.2,\002:\002,e8.2"
	    ",\002] \002,\002[\002,e8.2,\002:\002,e8.2,\002] \002,\002\"\002,"
	    "1a8,\002\" \002,\002notitle with lines, \002,1a1)";
    static char fmt_3000[] = "(2x,e11.5,2x,e11.5)";
    static char fmt_2850[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with dots\002)";
    static char fmt_2851[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with points\002)";
    static char fmt_2852[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with lines\002)";
    static char fmt_2855[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with dots, \002,1a1)";
    static char fmt_2856[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with points, \002,1a1)";
    static char fmt_2857[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with lines, \002,1a1)";
    static char fmt_2870[] = "(\002     \002,\002\"\002,1a8,\002\"\002,\002n"
	    "otitle  with dots\002)";
    static char fmt_2871[] = "(\002     \002,\002\"\002,1a8,\002\"\002,\002n"
	    "otitle  with points\002)";
    static char fmt_2872[] = "(\002     \002,\002\"\002,1a8,\002\"\002,\002n"
	    "otitle  with lines\002)";
    static char fmt_2875[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with dots, \002,1a1)";
    static char fmt_2876[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with points, \002,1a1)";
    static char fmt_2877[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with lines, \002,1a1)";
    static char fmt_2890[] = "(\002     \002,\002\"\002,1a8,\002\"\002,\002n"
	    "otitle  with dots\002)";
    static char fmt_2891[] = "(\002     \002,\002\"\002,1a8,\002\"\002,\002n"
	    "otitle  with points\002)";
    static char fmt_2892[] = "(\002     \002,\002\"\002,1a8,\002\"\002,\002n"
	    "otitle  with lines\002)";
    static char fmt_2895[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with dots, \002,1a1)";
    static char fmt_2896[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with points, \002,1a1)";
    static char fmt_2897[] = "(\002     \002,\002\"\002,1a8,\002\" \002,\002"
	    "notitle with lines, \002,1a1)";
    static char fmt_2910[] = "(\002     \002,\002\"\002,1a8,\002\"\002,\002n"
	    "otitle  with dots\002)";
    static char fmt_2911[] = "(\002     \002,\002\"\002,1a8,\002\"\002,\002n"
	    "otitle  with points\002)";
    static char fmt_2912[] = "(\002     \002,\002\"\002,1a8,\002\"\002,\002n"
	    "otitle  with lines\002)";

    /* System generated locals */
    integer i__1;
    olist o__1;
    cllist cl__1;
    static char equiv_0[8], equiv_1[8];

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_rsfi(icilist *), e_rsfi(void), f_open(olist *), s_wsfe(cilist 
	    *), e_wsfe(void), f_clos(cllist *);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int quamesslen_(char *, integer *, char *, ftnlen,
	     ftnlen);
    static integer iun, iun2;
    static char line[1*82];
    static integer iun22;
    static doublereal size, xmin, ymin, xmax, ymax;
#define file1 (equiv_0)
#define file8 (equiv_0)
#define anum1 (equiv_1)
#define anum8 (equiv_1)
    static integer nchar;
    static char dummy[8];
    static doublereal xsize, ysize, xcenter, ycenter;

    /* Fortran I/O blocks */
    static icilist io___401 = { 0, dummy, 0, fmt_1100, 8, 1 };
    static icilist io___402 = { 0, dummy, 0, fmt_1200, 8, 1 };
    static icilist io___403 = { 0, dummy, 0, fmt_1300, 8, 1 };
    static icilist io___404 = { 0, dummy, 0, fmt_1400, 8, 1 };
    static icilist io___405 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___408 = { 0, 0, 0, fmt_2250, 0 };
    static cilist io___411 = { 0, 0, 0, fmt_2270, 0 };
    static cilist io___412 = { 0, 0, 0, fmt_2280, 0 };
    static cilist io___422 = { 0, 0, 0, fmt_2350, 0 };
    static icilist io___424 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___425 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___426 = { 0, 0, 0, fmt_2800, 0 };
    static cilist io___427 = { 0, 0, 0, fmt_2803, 0 };
    static cilist io___428 = { 0, 0, 0, fmt_2805, 0 };
    static cilist io___429 = { 0, 0, 0, fmt_2830, 0 };
    static cilist io___430 = { 0, 0, 0, fmt_2833, 0 };
    static cilist io___431 = { 0, 0, 0, fmt_2835, 0 };
    static cilist io___433 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___434 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___435 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___436 = { 0, 0, 0, fmt_2850, 0 };
    static cilist io___437 = { 0, 0, 0, fmt_2851, 0 };
    static cilist io___438 = { 0, 0, 0, fmt_2852, 0 };
    static cilist io___439 = { 0, 0, 0, fmt_2855, 0 };
    static cilist io___440 = { 0, 0, 0, fmt_2856, 0 };
    static cilist io___441 = { 0, 0, 0, fmt_2857, 0 };
    static cilist io___442 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___443 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___444 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___445 = { 0, 0, 0, fmt_2870, 0 };
    static cilist io___446 = { 0, 0, 0, fmt_2871, 0 };
    static cilist io___447 = { 0, 0, 0, fmt_2872, 0 };
    static cilist io___448 = { 0, 0, 0, fmt_2875, 0 };
    static cilist io___449 = { 0, 0, 0, fmt_2876, 0 };
    static cilist io___450 = { 0, 0, 0, fmt_2877, 0 };
    static cilist io___451 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___452 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___453 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___454 = { 0, 0, 0, fmt_2890, 0 };
    static cilist io___455 = { 0, 0, 0, fmt_2891, 0 };
    static cilist io___456 = { 0, 0, 0, fmt_2892, 0 };
    static cilist io___457 = { 0, 0, 0, fmt_2895, 0 };
    static cilist io___458 = { 0, 0, 0, fmt_2896, 0 };
    static cilist io___459 = { 0, 0, 0, fmt_2897, 0 };
    static cilist io___460 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___461 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___462 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___463 = { 0, 0, 0, fmt_2910, 0 };
    static cilist io___464 = { 0, 0, 0, fmt_2911, 0 };
    static cilist io___465 = { 0, 0, 0, fmt_2912, 0 };
    static cilist io___466 = { 0, 0, 0, fmt_3000, 0 };



    /* Parameter adjustments */
    --title;
    z5 -= 3;
    z4 -= 3;
    z3 -= 3;
    z2 -= 3;
    z__ -= 3;

    /* Function Body */

/*        convert the user-specified Fortran unit number to */
/*        character format */

    if (*iw >= 0 && *iw <= 9) {
	s_wsfi(&io___401);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 10 && *iw <= 99) {
	s_wsfi(&io___402);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 100 && *iw <= 999) {
	s_wsfi(&io___403);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 1000 && *iw <= 9999) {
	s_wsfi(&io___404);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

/* L2000: */
    s_rsfi(&io___405);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

/*        construct the file name on which the Gnuplot instructions */
/*        are to be written */

    *(unsigned char *)&file1[0] = *(unsigned char *)&gn[0];
    *(unsigned char *)&file1[1] = *(unsigned char *)&gn[1];
    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2200: */
    }

/*        open the fortran file with the unit 87 and name file8 */

    iun = 87;
    o__1.oerr = 0;
    o__1.ounit = iun;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

/* L2250: */

    io___408.ciunit = iun;
    s_wsfe(&io___408);
    e_wsfe();

/*        generate the title for the plot */

    *(unsigned char *)&line[0] = *(unsigned char *)&blank[0];
    *(unsigned char *)&line[1] = *(unsigned char *)&blank[0];
    *(unsigned char *)&line[2] = *(unsigned char *)&quo[0];

    quamesslen_(title + 1, &nchar, line + 3, (ftnlen)1, (ftnlen)1);

    *(unsigned char *)&line[nchar + 3] = *(unsigned char *)&quo[0];
/* L2270: */

    io___411.ciunit = iun;
    s_wsfe(&io___411);
    i__1 = nchar + 4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, line + (i__ - 1), (ftnlen)1);
    }
    e_wsfe();

/* L2280: */
    io___412.ciunit = iun;
    s_wsfe(&io___412);
    e_wsfe();

/*        find the limits for both x and y */

    xmin = 1e30;
    ymin = 1e30;
    xmax = -1e20;
    ymax = -1e20;

    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (z__[(i__ << 1) + 1] < xmin) {
	    xmin = z__[(i__ << 1) + 1];
	}
	if (z__[(i__ << 1) + 2] < ymin) {
	    ymin = z__[(i__ << 1) + 2];
	}
	if (z__[(i__ << 1) + 1] > xmax) {
	    xmax = z__[(i__ << 1) + 1];
	}
	if (z__[(i__ << 1) + 2] > ymax) {
	    ymax = z__[(i__ << 1) + 2];
	}
/* L2300: */
    }

    if (*inumgr == 1) {
	goto L2345;
    }

    i__1 = *n2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (z2[(i__ << 1) + 1] < xmin) {
	    xmin = z2[(i__ << 1) + 1];
	}
	if (z2[(i__ << 1) + 2] < ymin) {
	    ymin = z2[(i__ << 1) + 2];
	}
	if (z2[(i__ << 1) + 1] > xmax) {
	    xmax = z2[(i__ << 1) + 1];
	}
	if (z2[(i__ << 1) + 2] > ymax) {
	    ymax = z2[(i__ << 1) + 2];
	}
/* L2310: */
    }

    if (*inumgr == 2) {
	goto L2345;
    }

    i__1 = *n3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (z3[(i__ << 1) + 1] < xmin) {
	    xmin = z3[(i__ << 1) + 1];
	}
	if (z3[(i__ << 1) + 2] < ymin) {
	    ymin = z3[(i__ << 1) + 2];
	}
	if (z3[(i__ << 1) + 1] > xmax) {
	    xmax = z3[(i__ << 1) + 1];
	}
	if (z3[(i__ << 1) + 2] > ymax) {
	    ymax = z3[(i__ << 1) + 2];
	}
/* L2320: */
    }

    if (*inumgr == 3) {
	goto L2345;
    }

    i__1 = *n4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (z4[(i__ << 1) + 1] < xmin) {
	    xmin = z4[(i__ << 1) + 1];
	}
	if (z4[(i__ << 1) + 2] < ymin) {
	    ymin = z4[(i__ << 1) + 2];
	}
	if (z4[(i__ << 1) + 1] > xmax) {
	    xmax = z4[(i__ << 1) + 1];
	}
	if (z4[(i__ << 1) + 2] > ymax) {
	    ymax = z4[(i__ << 1) + 2];
	}
/* L2330: */
    }

    if (*inumgr == 4) {
	goto L2345;
    }

    i__1 = *n5;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (z5[(i__ << 1) + 1] < xmin) {
	    xmin = z5[(i__ << 1) + 1];
	}
	if (z5[(i__ << 1) + 2] < ymin) {
	    ymin = z5[(i__ << 1) + 2];
	}
	if (z5[(i__ << 1) + 1] > xmax) {
	    xmax = z5[(i__ << 1) + 1];
	}
	if (z5[(i__ << 1) + 2] > ymax) {
	    ymax = z5[(i__ << 1) + 2];
	}
/* L2340: */
    }

L2345:

    xcenter = (xmin + xmax) / 2;
    ycenter = (ymax + ymin) / 2;

    xsize = xmax - xmin;
    ysize = ymax - ymin;
    size = xsize;
    if (ysize > size) {
	size = ysize;
    }
    size *= 1.2f;

    xmin = xcenter - size / 2;
    xmax = xcenter + size / 2;
    ymin = ycenter - size / 2;
    ymax = ycenter + size / 2;

/*        set the size of the stupid thing */

/* ccc 2350 format(2x,' set size 0.75,1.0') */
/* L2350: */
    io___422.ciunit = iun;
    s_wsfe(&io___422);
    e_wsfe();

/*        write the instructions */

/* L2400: */
    iun2 = *iw + 100000;
    s_wsfi(&io___424);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___425);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2600: */
    }

/* L2800: */
/* L2803: */
/* L2805: */

    if (*inumgr == 1 && *itype1 == 1) {
	io___426.ciunit = iun;
	s_wsfe(&io___426);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 1 && *itype1 == 2) {
	io___427.ciunit = iun;
	s_wsfe(&io___427);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 1 && *itype1 == 3) {
	io___428.ciunit = iun;
	s_wsfe(&io___428);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/* L2830: */

/* L2833: */

/* L2835: */

    if (*inumgr != 1 && *itype1 == 1) {
	io___429.ciunit = iun;
	s_wsfe(&io___429);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 1 && *itype1 == 2) {
	io___430.ciunit = iun;
	s_wsfe(&io___430);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 1 && *itype1 == 3) {
	io___431.ciunit = iun;
	s_wsfe(&io___431);
	do_fio(&c__1, (char *)&xmin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ymax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

/*        write the first data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___433.ciunit = iun22;
    s_wsfe(&io___433);
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&z__[(i__ << 1) + 1], (ftnlen)sizeof(doublereal)
		);
	do_fio(&c__1, (char *)&z__[(i__ << 1) + 2], (ftnlen)sizeof(doublereal)
		);
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the second data file */

    if (*inumgr == 1) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 1) {
	return 0;
    }

    iun2 = *iw + 200000;
    s_wsfi(&io___434);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___435);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2840: */
    }

/* L2850: */
/* L2851: */
/* L2852: */

    if (*inumgr == 2 && *itype2 == 1) {
	io___436.ciunit = iun;
	s_wsfe(&io___436);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 2 && *itype2 == 2) {
	io___437.ciunit = iun;
	s_wsfe(&io___437);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 2 && *itype2 == 3) {
	io___438.ciunit = iun;
	s_wsfe(&io___438);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/* L2855: */
/* L2856: */
/* L2857: */

    if (*inumgr != 2 && *itype2 == 1) {
	io___439.ciunit = iun;
	s_wsfe(&io___439);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 2 && *itype2 == 2) {
	io___440.ciunit = iun;
	s_wsfe(&io___440);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 2 && *itype2 == 3) {
	io___441.ciunit = iun;
	s_wsfe(&io___441);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

/*        write the second data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___442.ciunit = iun22;
    s_wsfe(&io___442);
    i__1 = *n2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&z2[(i__ << 1) + 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&z2[(i__ << 1) + 2], (ftnlen)sizeof(doublereal))
		;
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the third data file */

    if (*inumgr == 2) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 2) {
	return 0;
    }
    iun2 = *iw + 300000;
    s_wsfi(&io___443);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___444);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2860: */
    }

/* L2870: */
/* L2871: */
/* L2872: */

    if (*inumgr == 3 && *itype3 == 1) {
	io___445.ciunit = iun;
	s_wsfe(&io___445);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 3 && *itype3 == 2) {
	io___446.ciunit = iun;
	s_wsfe(&io___446);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 3 && *itype3 == 3) {
	io___447.ciunit = iun;
	s_wsfe(&io___447);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/* L2875: */
/* L2876: */
/* L2877: */

    if (*inumgr != 3 && *itype3 == 1) {
	io___448.ciunit = iun;
	s_wsfe(&io___448);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 3 && *itype3 == 2) {
	io___449.ciunit = iun;
	s_wsfe(&io___449);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 3 && *itype3 == 3) {
	io___450.ciunit = iun;
	s_wsfe(&io___450);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

/*        write the third data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___451.ciunit = iun22;
    s_wsfe(&io___451);
    i__1 = *n3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&z3[(i__ << 1) + 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&z3[(i__ << 1) + 2], (ftnlen)sizeof(doublereal))
		;
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the forth data file */

    if (*inumgr == 3) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 3) {
	return 0;
    }

    iun2 = *iw + 400000;
    s_wsfi(&io___452);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___453);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2880: */
    }

/* L2890: */
/* L2891: */
/* L2892: */

    if (*inumgr == 4 && *itype4 == 1) {
	io___454.ciunit = iun;
	s_wsfe(&io___454);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 4 && *itype4 == 2) {
	io___455.ciunit = iun;
	s_wsfe(&io___455);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 4 && *itype4 == 3) {
	io___456.ciunit = iun;
	s_wsfe(&io___456);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/* L2895: */
/* L2896: */
/* L2897: */

    if (*inumgr != 4 && *itype4 == 1) {
	io___457.ciunit = iun;
	s_wsfe(&io___457);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 4 && *itype4 == 2) {
	io___458.ciunit = iun;
	s_wsfe(&io___458);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 4 && *itype4 == 3) {
	io___459.ciunit = iun;
	s_wsfe(&io___459);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

/*        write the forth data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___460.ciunit = iun22;
    s_wsfe(&io___460);
    i__1 = *n4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&z4[(i__ << 1) + 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&z4[(i__ << 1) + 2], (ftnlen)sizeof(doublereal))
		;
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the fifth data file */

    if (*inumgr == 4) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 4) {
	return 0;
    }

    iun2 = *iw + 500000;
    s_wsfi(&io___461);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___462);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2900: */
    }

/* L2910: */
/* L2911: */
/* L2912: */

    if (*itype5 == 1) {
	io___463.ciunit = iun;
	s_wsfe(&io___463);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*itype5 == 2) {
	io___464.ciunit = iun;
	s_wsfe(&io___464);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*itype5 == 3) {
	io___465.ciunit = iun;
	s_wsfe(&io___465);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/*        write the fifth data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);


    io___466.ciunit = iun22;
    s_wsfe(&io___466);
    i__1 = *n5;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&z5[(i__ << 1) + 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&z5[(i__ << 1) + 2], (ftnlen)sizeof(doublereal))
		;
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = iun;
    cl__1.csta = 0;
    f_clos(&cl__1);

    return 0;
} /* zquaplo0_ */

#undef anum8
#undef anum1
#undef file8
#undef file1







/* Subroutine */ int zquagraph_(integer *iw, doublereal *z__, integer *n, 
	integer *itype1, char *title, ftnlen title_len)
{
    extern /* Subroutine */ int zquagrap0_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);
    static integer n2, n3, n4, n5;
    static doublereal z2[2]	/* was [2][1] */, z3[2]	/* was [2][1] */, z4[
	    2]	/* was [2][1] */, z5[2]	/* was [2][1] */;
    static integer itype2, itype3, itype4, itype5, inumgr;


    /* Parameter adjustments */
    --title;
    z__ -= 3;

    /* Function Body */
    inumgr = 1;

    zquagrap0_(iw, &z__[3], z2, z3, z4, z5, n, &n2, &n3, &n4, &n5, title + 1, 
	    &inumgr, itype1, &itype2, &itype3, &itype4, &itype5, (ftnlen)1);

    return 0;
} /* zquagraph_ */






/* Subroutine */ int zquagraph2_(integer *iw, doublereal *z__, integer *n, 
	integer *itype1, doublereal *z2, integer *n2, integer *itype2, char *
	title, ftnlen title_len)
{
    extern /* Subroutine */ int zquagrap0_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);
    static integer n3, n4, n5;
    static doublereal z3[2]	/* was [2][1] */, z4[2]	/* was [2][1] */, z5[
	    2]	/* was [2][1] */;
    static integer itype3, itype4, itype5, inumgr;


    /* Parameter adjustments */
    --title;
    z2 -= 3;
    z__ -= 3;

    /* Function Body */
    inumgr = 2;

    zquagrap0_(iw, &z__[3], &z2[3], z3, z4, z5, n, n2, &n3, &n4, &n5, title + 
	    1, &inumgr, itype1, itype2, &itype3, &itype4, &itype5, (ftnlen)1);

    return 0;
} /* zquagraph2_ */






/* Subroutine */ int zquagraph3_(integer *iw, doublereal *z__, integer *n, 
	integer *itype1, doublereal *z2, integer *n2, integer *itype2, 
	doublereal *z3, integer *n3, integer *itype3, char *title, ftnlen 
	title_len)
{
    extern /* Subroutine */ int zquagrap0_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);
    static integer n4, n5;
    static doublereal z4[2]	/* was [2][1] */, z5[2]	/* was [2][1] */;
    static integer itype4, itype5, inumgr;


    /* Parameter adjustments */
    --title;
    z3 -= 3;
    z2 -= 3;
    z__ -= 3;

    /* Function Body */
    inumgr = 3;

    zquagrap0_(iw, &z__[3], &z2[3], &z3[3], z4, z5, n, n2, n3, &n4, &n5, 
	    title + 1, &inumgr, itype1, itype2, itype3, &itype4, &itype5, (
	    ftnlen)1);

    return 0;
} /* zquagraph3_ */






/* Subroutine */ int zquagraph4_(integer *iw, doublereal *z__, integer *n, 
	integer *itype1, doublereal *z2, integer *n2, integer *itype2, 
	doublereal *z3, integer *n3, integer *itype3, doublereal *z4, integer 
	*n4, integer *itype4, char *title, ftnlen title_len)
{
    extern /* Subroutine */ int zquagrap0_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);
    static integer n5;
    static doublereal z5[2]	/* was [2][1] */;
    static integer itype5, inumgr;


    /* Parameter adjustments */
    --title;
    z4 -= 3;
    z3 -= 3;
    z2 -= 3;
    z__ -= 3;

    /* Function Body */
    inumgr = 4;

    zquagrap0_(iw, &z__[3], &z2[3], &z3[3], &z4[3], z5, n, n2, n3, n4, &n5, 
	    title + 1, &inumgr, itype1, itype2, itype3, itype4, &itype5, (
	    ftnlen)1);

    return 0;
} /* zquagraph4_ */






/* Subroutine */ int zquagraph5_(integer *iw, doublereal *z__, integer *n, 
	integer *itype1, doublereal *z2, integer *n2, integer *itype2, 
	doublereal *z3, integer *n3, integer *itype3, doublereal *z4, integer 
	*n4, integer *itype4, doublereal *z5, integer *n5, integer *itype5, 
	char *title, ftnlen title_len)
{
    extern /* Subroutine */ int zquagrap0_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen);
    static integer inumgr;


    /* Parameter adjustments */
    --title;
    z5 -= 3;
    z4 -= 3;
    z3 -= 3;
    z2 -= 3;
    z__ -= 3;

    /* Function Body */
    inumgr = 5;

    zquagrap0_(iw, &z__[3], &z2[3], &z3[3], &z4[3], &z5[3], n, n2, n3, n4, n5,
	     title + 1, &inumgr, itype1, itype2, itype3, itype4, itype5, (
	    ftnlen)1);

    return 0;
} /* zquagraph5_ */






/* Subroutine */ int zquagrap0_(integer *iw, doublereal *z__, doublereal *z2, 
	doublereal *z3, doublereal *z4, doublereal *z5, integer *n, integer *
	n2, integer *n3, integer *n4, integer *n5, char *title, integer *
	inumgr, integer *itype1, integer *itype2, integer *itype3, integer *
	itype4, integer *itype5, ftnlen title_len)
{
    /* Initialized data */

    static char gn[1*2] = "g" "n";
    static char blank[1] = " ";
    static char quo[1] = "\"";
    static char backslash[1] = "\\";

    /* Format strings */
    static char fmt_1100[] = "(i1)";
    static char fmt_1200[] = "(i2)";
    static char fmt_1300[] = "(i3)";
    static char fmt_1400[] = "(i4)";
    static char fmt_2000[] = "(1a8)";
    static char fmt_2250[] = "(\002   # set terminal postscript\002,/,\002  "
	    " # set output \"plot.ps\"\002)";
    static char fmt_2300[] = "(\002  set title \002,80a1)";
    static char fmt_2350[] = "(\002   show title\002)";
    static char fmt_2400[] = "(i6)";
    static char fmt_2800[] = "(\002plot \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots\002)";
    static char fmt_2803[] = "(\002plot \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points\002)";
    static char fmt_2805[] = "(\002plot \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines\002)";
    static char fmt_2830[] = "(\002plot \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots, \002,1a1)";
    static char fmt_2831[] = "(\002plot \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points, \002,1a1)";
    static char fmt_2832[] = "(\002plot \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines, \002,1a1)";
    static char fmt_3000[] = "(2x,e11.5,2x,e11.5)";
    static char fmt_2850[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots\002)";
    static char fmt_2851[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points\002)";
    static char fmt_2852[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines\002)";
    static char fmt_2855[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots, \002,1a1)";
    static char fmt_2856[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points, \002,1a1)";
    static char fmt_2857[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines, \002,1a1)";
    static char fmt_2870[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots\002)";
    static char fmt_2871[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points\002)";
    static char fmt_2872[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines\002)";
    static char fmt_2875[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots, \002,1a1)";
    static char fmt_2876[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points, \002,1a1)";
    static char fmt_2877[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines, \002,1a1)";
    static char fmt_2890[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots\002)";
    static char fmt_2891[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points\002)";
    static char fmt_2892[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines\002)";
    static char fmt_2895[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots, \002,1a1)";
    static char fmt_2896[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points, \002,1a1)";
    static char fmt_2897[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines, \002,1a1)";
    static char fmt_2910[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with dots\002)";
    static char fmt_2911[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with points\002)";
    static char fmt_2912[] = "(\002     \002,\002\"\002,1a8,\002\"     \002"
	    ",\002notitle  with lines\002)";

    /* System generated locals */
    integer i__1;
    olist o__1;
    cllist cl__1;
    static char equiv_0[8], equiv_1[8];

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_rsfi(icilist *), e_rsfi(void), f_open(olist *), s_wsfe(cilist 
	    *), e_wsfe(void), f_clos(cllist *);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int quamesslen_(char *, integer *, char *, ftnlen,
	     ftnlen);
    static integer iun, iun2;
    static char line[1*82];
    static integer iun22;
#define file1 (equiv_0)
#define file8 (equiv_0)
#define anum1 (equiv_1)
#define anum8 (equiv_1)
    static integer nchar;
    static char dummy[8];

    /* Fortran I/O blocks */
    static icilist io___511 = { 0, dummy, 0, fmt_1100, 8, 1 };
    static icilist io___512 = { 0, dummy, 0, fmt_1200, 8, 1 };
    static icilist io___513 = { 0, dummy, 0, fmt_1300, 8, 1 };
    static icilist io___514 = { 0, dummy, 0, fmt_1400, 8, 1 };
    static icilist io___515 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___518 = { 0, 0, 0, fmt_2250, 0 };
    static cilist io___521 = { 0, 0, 0, fmt_2300, 0 };
    static cilist io___522 = { 0, 0, 0, fmt_2350, 0 };
    static icilist io___524 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___525 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___526 = { 0, 0, 0, fmt_2800, 0 };
    static cilist io___527 = { 0, 0, 0, fmt_2803, 0 };
    static cilist io___528 = { 0, 0, 0, fmt_2805, 0 };
    static cilist io___529 = { 0, 0, 0, fmt_2830, 0 };
    static cilist io___530 = { 0, 0, 0, fmt_2831, 0 };
    static cilist io___531 = { 0, 0, 0, fmt_2832, 0 };
    static cilist io___533 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___534 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___535 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___536 = { 0, 0, 0, fmt_2850, 0 };
    static cilist io___537 = { 0, 0, 0, fmt_2851, 0 };
    static cilist io___538 = { 0, 0, 0, fmt_2852, 0 };
    static cilist io___539 = { 0, 0, 0, fmt_2855, 0 };
    static cilist io___540 = { 0, 0, 0, fmt_2856, 0 };
    static cilist io___541 = { 0, 0, 0, fmt_2857, 0 };
    static cilist io___542 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___543 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___544 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___545 = { 0, 0, 0, fmt_2870, 0 };
    static cilist io___546 = { 0, 0, 0, fmt_2871, 0 };
    static cilist io___547 = { 0, 0, 0, fmt_2872, 0 };
    static cilist io___548 = { 0, 0, 0, fmt_2875, 0 };
    static cilist io___549 = { 0, 0, 0, fmt_2876, 0 };
    static cilist io___550 = { 0, 0, 0, fmt_2877, 0 };
    static cilist io___551 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___552 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___553 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___554 = { 0, 0, 0, fmt_2890, 0 };
    static cilist io___555 = { 0, 0, 0, fmt_2891, 0 };
    static cilist io___556 = { 0, 0, 0, fmt_2892, 0 };
    static cilist io___557 = { 0, 0, 0, fmt_2895, 0 };
    static cilist io___558 = { 0, 0, 0, fmt_2896, 0 };
    static cilist io___559 = { 0, 0, 0, fmt_2897, 0 };
    static cilist io___560 = { 0, 0, 0, fmt_3000, 0 };
    static icilist io___561 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___562 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___563 = { 0, 0, 0, fmt_2910, 0 };
    static cilist io___564 = { 0, 0, 0, fmt_2911, 0 };
    static cilist io___565 = { 0, 0, 0, fmt_2912, 0 };
    static cilist io___566 = { 0, 0, 0, fmt_3000, 0 };



    /* Parameter adjustments */
    --title;
    z5 -= 3;
    z4 -= 3;
    z3 -= 3;
    z2 -= 3;
    z__ -= 3;

    /* Function Body */

/*        convert the user-specified Fortran unit number to */
/*        character format */

    if (*iw >= 0 && *iw <= 9) {
	s_wsfi(&io___511);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 10 && *iw <= 99) {
	s_wsfi(&io___512);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 100 && *iw <= 999) {
	s_wsfi(&io___513);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 1000 && *iw <= 9999) {
	s_wsfi(&io___514);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

/* L2000: */
    s_rsfi(&io___515);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

/*        construct the file name on which the Gnuplot instructions */
/*        are to be written */

    *(unsigned char *)&file1[0] = *(unsigned char *)&gn[0];
    *(unsigned char *)&file1[1] = *(unsigned char *)&gn[1];
    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2200: */
    }

/*        open the fortran file with the unit 87 and name file8 */

    iun = 87;
    o__1.oerr = 0;
    o__1.ounit = iun;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

/* L2250: */

    io___518.ciunit = iun;
    s_wsfe(&io___518);
    e_wsfe();

/* L2255: */

/*        generate the title for the plot */

    *(unsigned char *)&line[0] = *(unsigned char *)&blank[0];
    *(unsigned char *)&line[1] = *(unsigned char *)&blank[0];
    *(unsigned char *)&line[2] = *(unsigned char *)&quo[0];

    quamesslen_(title + 1, &nchar, line + 3, (ftnlen)1, (ftnlen)1);

    *(unsigned char *)&line[nchar + 3] = *(unsigned char *)&quo[0];
/* L2300: */
    io___521.ciunit = iun;
    s_wsfe(&io___521);
    i__1 = nchar + 4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, line + (i__ - 1), (ftnlen)1);
    }
    e_wsfe();

/* L2350: */
    io___522.ciunit = iun;
    s_wsfe(&io___522);
    e_wsfe();

/*        write the instructions */

/* L2400: */
    iun2 = *iw + 100000;
    s_wsfi(&io___524);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___525);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2600: */
    }

/* L2800: */
/* L2803: */
/* L2805: */

    if (*inumgr == 1 && *itype1 == 1) {
	io___526.ciunit = iun;
	s_wsfe(&io___526);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 1 && *itype1 == 2) {
	io___527.ciunit = iun;
	s_wsfe(&io___527);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 1 && *itype1 == 3) {
	io___528.ciunit = iun;
	s_wsfe(&io___528);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/* L2830: */
/* L2831: */
/* L2832: */

    if (*inumgr != 1 && *itype1 == 1) {
	io___529.ciunit = iun;
	s_wsfe(&io___529);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 1 && *itype1 == 2) {
	io___530.ciunit = iun;
	s_wsfe(&io___530);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 1 && *itype1 == 3) {
	io___531.ciunit = iun;
	s_wsfe(&io___531);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

/*        write the first data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___533.ciunit = iun22;
    s_wsfe(&io___533);
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&z__[(i__ << 1) + 1], (ftnlen)sizeof(doublereal)
		);
	do_fio(&c__1, (char *)&z__[(i__ << 1) + 2], (ftnlen)sizeof(doublereal)
		);
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the second data file */

    if (*inumgr == 1) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 1) {
	return 0;
    }
    iun2 = *iw + 200000;
    s_wsfi(&io___534);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___535);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2840: */
    }

/* L2850: */
/* L2851: */
/* L2852: */

    if (*inumgr == 2 && *itype2 == 1) {
	io___536.ciunit = iun;
	s_wsfe(&io___536);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 2 && *itype2 == 2) {
	io___537.ciunit = iun;
	s_wsfe(&io___537);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 2 && *itype2 == 3) {
	io___538.ciunit = iun;
	s_wsfe(&io___538);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }


    if (*inumgr != 2 && *itype2 == 1) {
	io___539.ciunit = iun;
	s_wsfe(&io___539);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 2 && *itype2 == 2) {
	io___540.ciunit = iun;
	s_wsfe(&io___540);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 2 && *itype2 == 3) {
	io___541.ciunit = iun;
	s_wsfe(&io___541);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }


/*        write the second data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___542.ciunit = iun22;
    s_wsfe(&io___542);
    i__1 = *n2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&z2[(i__ << 1) + 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&z2[(i__ << 1) + 2], (ftnlen)sizeof(doublereal))
		;
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the third data file */

    if (*inumgr == 2) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 2) {
	return 0;
    }
    iun2 = *iw + 300000;
    s_wsfi(&io___543);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___544);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2860: */
    }

/* L2870: */
/* L2871: */
/* L2872: */

    if (*inumgr == 3 && *itype3 == 1) {
	io___545.ciunit = iun;
	s_wsfe(&io___545);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 3 && *itype3 == 2) {
	io___546.ciunit = iun;
	s_wsfe(&io___546);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 3 && *itype3 == 3) {
	io___547.ciunit = iun;
	s_wsfe(&io___547);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }


    if (*inumgr != 3 && *itype3 == 1) {
	io___548.ciunit = iun;
	s_wsfe(&io___548);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 3 && *itype3 == 2) {
	io___549.ciunit = iun;
	s_wsfe(&io___549);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 3 && *itype3 == 3) {
	io___550.ciunit = iun;
	s_wsfe(&io___550);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }


/*        write the third data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___551.ciunit = iun22;
    s_wsfe(&io___551);
    i__1 = *n3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&z3[(i__ << 1) + 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&z3[(i__ << 1) + 2], (ftnlen)sizeof(doublereal))
		;
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the forth data file */

    if (*inumgr == 3) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 3) {
	return 0;
    }

    iun2 = *iw + 400000;
    s_wsfi(&io___552);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___553);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2880: */
    }

/* L2890: */
/* L2891: */
/* L2892: */

    if (*inumgr == 4 && *itype4 == 1) {
	io___554.ciunit = iun;
	s_wsfe(&io___554);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 4 && *itype4 == 2) {
	io___555.ciunit = iun;
	s_wsfe(&io___555);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

    if (*inumgr == 4 && *itype4 == 3) {
	io___556.ciunit = iun;
	s_wsfe(&io___556);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }


    if (*inumgr != 4 && *itype4 == 1) {
	io___557.ciunit = iun;
	s_wsfe(&io___557);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 4 && *itype4 == 2) {
	io___558.ciunit = iun;
	s_wsfe(&io___558);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }

    if (*inumgr != 4 && *itype4 == 3) {
	io___559.ciunit = iun;
	s_wsfe(&io___559);
	do_fio(&c__1, file8, (ftnlen)8);
	do_fio(&c__1, backslash, (ftnlen)1);
	e_wsfe();
    }


/*        write the forth data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    io___560.ciunit = iun22;
    s_wsfe(&io___560);
    i__1 = *n4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&z4[(i__ << 1) + 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&z4[(i__ << 1) + 2], (ftnlen)sizeof(doublereal))
		;
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*       if the user so requested - write the instructions for the */
/*       plotting the fifth data file */

    if (*inumgr == 4) {
	cl__1.cerr = 0;
	cl__1.cunit = iun;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (*inumgr == 4) {
	return 0;
    }

    iun2 = *iw + 500000;
    s_wsfi(&io___561);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___562);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2900: */
    }

/* L2910: */
/* L2911: */
/* L2912: */

    if (*itype5 == 1) {
	io___563.ciunit = iun;
	s_wsfe(&io___563);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*itype5 == 2) {
	io___564.ciunit = iun;
	s_wsfe(&io___564);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }
    if (*itype5 == 3) {
	io___565.ciunit = iun;
	s_wsfe(&io___565);
	do_fio(&c__1, file8, (ftnlen)8);
	e_wsfe();
    }

/*        write the fifth data file to be plotted */

    iun22 = 88;
    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);


    io___566.ciunit = iun22;
    s_wsfe(&io___566);
    i__1 = *n5;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&z5[(i__ << 1) + 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&z5[(i__ << 1) + 2], (ftnlen)sizeof(doublereal))
		;
    }
    e_wsfe();

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = iun;
    cl__1.csta = 0;
    f_clos(&cl__1);

    return 0;
} /* zquagrap0_ */

#undef anum8
#undef anum1
#undef file8
#undef file1







/* Subroutine */ int qua_labels_conn__(integer *iw)
{
    /* Initialized data */

    static char quo[1] = "\"";
    static char gnl[1*3] = "g" "n" "l";

    /* Format strings */
    static char fmt_1100[] = "(i1)";
    static char fmt_1200[] = "(i2)";
    static char fmt_1300[] = "(i3)";
    static char fmt_1400[] = "(i4)";
    static char fmt_2000[] = "(1a8)";
    static char fmt_2410[] = "(4x,\002  load \002,a1,\002gnlb\002,2a1)";
    static char fmt_2510[] = "(4x,\002  load \002,a1,\002gn\002,2a1)";
    static char fmt_2420[] = "(4x,\002  load \002,a1,\002gnlb\002,3a1)";
    static char fmt_2520[] = "(4x,\002  load \002,a1,\002gn\002,3a1)";
    static char fmt_2430[] = "(4x,\002  load \002,a1,\002gnlb\002,4a1)";
    static char fmt_2530[] = "(4x,\002  load \002,a1,\002gn\002,4a1)";
    static char fmt_2440[] = "(4x,\002  load \002,a1,\002gnlb\002,5a1)";
    static char fmt_2540[] = "(4x,\002  load \002,a1,\002gn\002,5a1)";

    /* System generated locals */
    olist o__1;
    cllist cl__1;
    static char equiv_0[20], equiv_1[8];

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_rsfi(icilist *), e_rsfi(void), f_open(olist *), s_wsfe(cilist 
	    *), e_wsfe(void), f_clos(cllist *);

    /* Local variables */
    static integer i__, iun;
#define file1 (equiv_0)
#define file8 (equiv_0)
#define anum1 (equiv_1)
#define anum8 (equiv_1)
    static char dummy[8];

    /* Fortran I/O blocks */
    static icilist io___575 = { 0, dummy, 0, fmt_1100, 8, 1 };
    static icilist io___576 = { 0, dummy, 0, fmt_1200, 8, 1 };
    static icilist io___577 = { 0, dummy, 0, fmt_1300, 8, 1 };
    static icilist io___578 = { 0, dummy, 0, fmt_1400, 8, 1 };
    static icilist io___579 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___582 = { 0, 0, 0, fmt_2410, 0 };
    static cilist io___583 = { 0, 0, 0, fmt_2510, 0 };
    static cilist io___584 = { 0, 0, 0, fmt_2420, 0 };
    static cilist io___585 = { 0, 0, 0, fmt_2520, 0 };
    static cilist io___586 = { 0, 0, 0, fmt_2430, 0 };
    static cilist io___587 = { 0, 0, 0, fmt_2530, 0 };
    static cilist io___588 = { 0, 0, 0, fmt_2440, 0 };
    static cilist io___589 = { 0, 0, 0, fmt_2540, 0 };




/*        convert the user-specified Fortran unit number to */
/*        character format */

    if (*iw >= 0 && *iw <= 9) {
	s_wsfi(&io___575);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 10 && *iw <= 99) {
	s_wsfi(&io___576);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 100 && *iw <= 999) {
	s_wsfi(&io___577);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 1000 && *iw <= 9999) {
	s_wsfi(&io___578);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

/* L2000: */
    s_rsfi(&io___579);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

/*        construct the file name on which the Gnuplot instructions */
/*        are to be written */

    *(unsigned char *)&file1[0] = *(unsigned char *)&gnl[0];
    *(unsigned char *)&file1[1] = *(unsigned char *)&gnl[1];
    *(unsigned char *)&file1[2] = *(unsigned char *)&gnl[2];
    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 2] = *(unsigned char *)&anum1[i__ - 1];
/* L2200: */
    }

/*        open the fortran file with the unit 87 and name file8 */

    iun = 87;
    o__1.oerr = 0;
    o__1.ounit = iun;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

/*       write the "load" instructuins to the file we just opened */

    if (*iw >= 0 && *iw <= 9) {
	io___582.ciunit = iun;
	s_wsfe(&io___582);
	do_fio(&c__1, quo, (ftnlen)1);
	do_fio(&c__1, anum1, (ftnlen)1);
	do_fio(&c__1, quo, (ftnlen)1);
	e_wsfe();
    }

    if (*iw >= 0 && *iw <= 9) {
	io___583.ciunit = iun;
	s_wsfe(&io___583);
	do_fio(&c__1, quo, (ftnlen)1);
	do_fio(&c__1, anum1, (ftnlen)1);
	do_fio(&c__1, quo, (ftnlen)1);
	e_wsfe();
    }

    if (*iw >= 10 && *iw <= 99) {
	io___584.ciunit = iun;
	s_wsfe(&io___584);
	do_fio(&c__1, quo, (ftnlen)1);
	do_fio(&c__1, anum1, (ftnlen)1);
	do_fio(&c__1, anum1 + 1, (ftnlen)1);
	do_fio(&c__1, quo, (ftnlen)1);
	e_wsfe();
    }
    if (*iw >= 10 && *iw <= 99) {
	io___585.ciunit = iun;
	s_wsfe(&io___585);
	do_fio(&c__1, quo, (ftnlen)1);
	do_fio(&c__1, anum1, (ftnlen)1);
	do_fio(&c__1, anum1 + 1, (ftnlen)1);
	do_fio(&c__1, quo, (ftnlen)1);
	e_wsfe();
    }

    if (*iw >= 100 && *iw <= 999) {
	io___586.ciunit = iun;
	s_wsfe(&io___586);
	do_fio(&c__1, quo, (ftnlen)1);
	do_fio(&c__1, anum1, (ftnlen)1);
	do_fio(&c__1, anum1 + 1, (ftnlen)1);
	do_fio(&c__1, anum1 + 2, (ftnlen)1);
	do_fio(&c__1, quo, (ftnlen)1);
	e_wsfe();


	io___587.ciunit = iun;
	s_wsfe(&io___587);
	do_fio(&c__1, quo, (ftnlen)1);
	do_fio(&c__1, anum1, (ftnlen)1);
	do_fio(&c__1, anum1 + 1, (ftnlen)1);
	do_fio(&c__1, anum1 + 2, (ftnlen)1);
	do_fio(&c__1, quo, (ftnlen)1);
	e_wsfe();


    }



    if (*iw >= 1000 && *iw <= 9999) {
	io___588.ciunit = iun;
	s_wsfe(&io___588);
	do_fio(&c__1, quo, (ftnlen)1);
	do_fio(&c__1, anum1, (ftnlen)1);
	do_fio(&c__1, anum1 + 1, (ftnlen)1);
	do_fio(&c__1, anum1 + 2, (ftnlen)1);
	do_fio(&c__1, anum1 + 3, (ftnlen)1);
	do_fio(&c__1, quo, (ftnlen)1);
	e_wsfe();


	io___589.ciunit = iun;
	s_wsfe(&io___589);
	do_fio(&c__1, quo, (ftnlen)1);
	do_fio(&c__1, anum1, (ftnlen)1);
	do_fio(&c__1, anum1 + 1, (ftnlen)1);
	do_fio(&c__1, anum1 + 2, (ftnlen)1);
	do_fio(&c__1, anum1 + 3, (ftnlen)1);
	do_fio(&c__1, quo, (ftnlen)1);
	e_wsfe();


    }

    cl__1.cerr = 0;
    cl__1.cunit = iun;
    cl__1.csta = 0;
    f_clos(&cl__1);

    return 0;
} /* qua_labels_conn__ */

#undef anum8
#undef anum1
#undef file8
#undef file1







/* Subroutine */ int zqua_labels_int__(integer *iw, doublereal *zs, integer *
	labs, integer *n)
{
    /* Initialized data */

    static char quo[1] = "\"";
    static char gnlb[1*4] = "g" "n" "l" "b";

    /* Format strings */
    static char fmt_1100[] = "(i1)";
    static char fmt_1200[] = "(i2)";
    static char fmt_1300[] = "(i3)";
    static char fmt_1400[] = "(i4)";
    static char fmt_2000[] = "(1a8)";
    static char fmt_2410[] = "(4x,\002set label \002,i4,2x,1a1,i1,1a1,\002 a"
	    "t \002,e11.5,\002, \002,e11.5)";
    static char fmt_2420[] = "(4x,\002set label \002,i4,2x,1a1,i2,1a1,\002 a"
	    "t \002,e11.5,\002, \002,e11.5)";
    static char fmt_2430[] = "(4x,\002set label \002,i4,2x,1a1,i3,1a1,\002 a"
	    "t \002,e11.5,\002, \002,e11.5)";
    static char fmt_2440[] = "(4x,\002set label \002,i4,2x,1a1,i4,1a1,\002 a"
	    "t \002,e11.5,\002, \002,e11.5)";
    static char fmt_2450[] = "(4x,\002set label \002,i4,2x,1a1,i5,1a1,\002 a"
	    "t \002,e11.5,\002, \002,e11.5)";

    /* System generated locals */
    integer i__1;
    olist o__1;
    cllist cl__1;
    static char equiv_0[20], equiv_1[20];

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_rsfi(icilist *), e_rsfi(void), f_open(olist *), s_wsfe(cilist 
	    *), e_wsfe(void), f_clos(cllist *);

    /* Local variables */
    static integer i__, iun;
#define file1 (equiv_0)
#define file8 (equiv_0)
#define anum1 (equiv_1)
#define anum8 (equiv_1)
    static char dummy[8];
    extern /* Subroutine */ int qua_labels_conn__(integer *);

    /* Fortran I/O blocks */
    static icilist io___598 = { 0, dummy, 0, fmt_1100, 8, 1 };
    static icilist io___599 = { 0, dummy, 0, fmt_1200, 8, 1 };
    static icilist io___600 = { 0, dummy, 0, fmt_1300, 8, 1 };
    static icilist io___601 = { 0, dummy, 0, fmt_1400, 8, 1 };
    static icilist io___602 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___605 = { 0, 0, 0, fmt_2410, 0 };
    static cilist io___606 = { 0, 0, 0, fmt_2420, 0 };
    static cilist io___607 = { 0, 0, 0, fmt_2430, 0 };
    static cilist io___608 = { 0, 0, 0, fmt_2440, 0 };
    static cilist io___609 = { 0, 0, 0, fmt_2450, 0 };



    /* Parameter adjustments */
    --labs;
    zs -= 3;

    /* Function Body */

/*        convert the user-specified Fortran unit number to */
/*        character format */

    if (*iw >= 0 && *iw <= 9) {
	s_wsfi(&io___598);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 10 && *iw <= 99) {
	s_wsfi(&io___599);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 100 && *iw <= 999) {
	s_wsfi(&io___600);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 1000 && *iw <= 9999) {
	s_wsfi(&io___601);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

/* L2000: */
    s_rsfi(&io___602);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

/*        construct the file name on which the Gnuplot instructions */
/*        are to be written */

    *(unsigned char *)&file1[0] = *(unsigned char *)&gnlb[0];
    *(unsigned char *)&file1[1] = *(unsigned char *)&gnlb[1];
    *(unsigned char *)&file1[2] = *(unsigned char *)&gnlb[2];
    *(unsigned char *)&file1[3] = *(unsigned char *)&gnlb[3];
    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 3] = *(unsigned char *)&anum1[i__ - 1];
/* L2200: */
    }

/*        open the fortran file with the unit 87 and name file8 */

    iun = 87;
    o__1.oerr = 0;
    o__1.ounit = iun;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

/*       write the labels to the file we just opened */

    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {

/* L2410: */

/* L2420: */

/* L2430: */

/* L2440: */

/* L2450: */

	if (labs[i__] >= 0 && labs[i__] <= 9) {
	    io___605.ciunit = iun;
	    s_wsfe(&io___605);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&labs[i__], (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&zs[(i__ << 1) + 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&zs[(i__ << 1) + 2], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}

	if (labs[i__] >= 10 && labs[i__] <= 99) {
	    io___606.ciunit = iun;
	    s_wsfe(&io___606);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&labs[i__], (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&zs[(i__ << 1) + 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&zs[(i__ << 1) + 2], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}

	if (labs[i__] >= 100 && labs[i__] <= 999) {
	    io___607.ciunit = iun;
	    s_wsfe(&io___607);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&labs[i__], (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&zs[(i__ << 1) + 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&zs[(i__ << 1) + 2], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}

	if (labs[i__] >= 1000 && labs[i__] <= 9999) {
	    io___608.ciunit = iun;
	    s_wsfe(&io___608);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&labs[i__], (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&zs[(i__ << 1) + 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&zs[(i__ << 1) + 2], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}

	if (labs[i__] >= 10000 && labs[i__] <= 99999) {
	    io___609.ciunit = iun;
	    s_wsfe(&io___609);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&labs[i__], (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&zs[(i__ << 1) + 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&zs[(i__ << 1) + 2], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}


/* L2600: */
    }
/* ccc    set label 1 "look" at 0.4, 0.4 */
/* ccc    set label 2 "fool" at 0.6, 0.4 */
    cl__1.cerr = 0;
    cl__1.cunit = iun;
    cl__1.csta = 0;
    f_clos(&cl__1);
    qua_labels_conn__(iw);

    return 0;
} /* zqua_labels_int__ */

#undef anum8
#undef anum1
#undef file8
#undef file1







/* Subroutine */ int qua_labels_int__(integer *iw, doublereal *x, doublereal *
	y, integer *labs, integer *n)
{
    /* Initialized data */

    static char quo[1] = "\"";
    static char gnlb[1*4] = "g" "n" "l" "b";

    /* Format strings */
    static char fmt_1100[] = "(i1)";
    static char fmt_1200[] = "(i2)";
    static char fmt_1300[] = "(i3)";
    static char fmt_1400[] = "(i4)";
    static char fmt_2000[] = "(1a8)";
    static char fmt_2410[] = "(4x,\002set label \002,i4,2x,1a1,i1,1a1,\002 a"
	    "t \002,e11.5,\002, \002,e11.5)";
    static char fmt_2420[] = "(4x,\002set label \002,i4,2x,1a1,i2,1a1,\002 a"
	    "t \002,e11.5,\002, \002,e11.5)";
    static char fmt_2430[] = "(4x,\002set label \002,i4,2x,1a1,i3,1a1,\002 a"
	    "t \002,e11.5,\002, \002,e11.5)";
    static char fmt_2440[] = "(4x,\002set label \002,i4,2x,1a1,i4,1a1,\002 a"
	    "t \002,e11.5,\002, \002,e11.5)";
    static char fmt_2450[] = "(4x,\002set label \002,i4,2x,1a1,i5,1a1,\002 a"
	    "t \002,e11.5,\002, \002,e11.5)";

    /* System generated locals */
    integer i__1;
    olist o__1;
    cllist cl__1;
    static char equiv_0[20], equiv_1[20];

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_rsfi(icilist *), e_rsfi(void), f_open(olist *), s_wsfe(cilist 
	    *), e_wsfe(void), f_clos(cllist *);

    /* Local variables */
    static integer i__, iun;
#define file1 (equiv_0)
#define file8 (equiv_0)
#define anum1 (equiv_1)
#define anum8 (equiv_1)
    static char dummy[8];
    extern /* Subroutine */ int qua_labels_conn__(integer *);

    /* Fortran I/O blocks */
    static icilist io___618 = { 0, dummy, 0, fmt_1100, 8, 1 };
    static icilist io___619 = { 0, dummy, 0, fmt_1200, 8, 1 };
    static icilist io___620 = { 0, dummy, 0, fmt_1300, 8, 1 };
    static icilist io___621 = { 0, dummy, 0, fmt_1400, 8, 1 };
    static icilist io___622 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___625 = { 0, 0, 0, fmt_2410, 0 };
    static cilist io___626 = { 0, 0, 0, fmt_2420, 0 };
    static cilist io___627 = { 0, 0, 0, fmt_2430, 0 };
    static cilist io___628 = { 0, 0, 0, fmt_2440, 0 };
    static cilist io___629 = { 0, 0, 0, fmt_2450, 0 };



    /* Parameter adjustments */
    --labs;
    --y;
    --x;

    /* Function Body */

/*        convert the user-specified Fortran unit number to */
/*        character format */

    if (*iw >= 0 && *iw <= 9) {
	s_wsfi(&io___618);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 10 && *iw <= 99) {
	s_wsfi(&io___619);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 100 && *iw <= 999) {
	s_wsfi(&io___620);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 1000 && *iw <= 9999) {
	s_wsfi(&io___621);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

/* L2000: */
    s_rsfi(&io___622);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

/*        construct the file name on which the Gnuplot instructions */
/*        are to be written */

    *(unsigned char *)&file1[0] = *(unsigned char *)&gnlb[0];
    *(unsigned char *)&file1[1] = *(unsigned char *)&gnlb[1];
    *(unsigned char *)&file1[2] = *(unsigned char *)&gnlb[2];
    *(unsigned char *)&file1[3] = *(unsigned char *)&gnlb[3];
    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 3] = *(unsigned char *)&anum1[i__ - 1];
/* L2200: */
    }

/*        open the fortran file with the unit 87 and name file8 */

    iun = 87;
    o__1.oerr = 0;
    o__1.ounit = iun;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

/*       write the labels to the file we just opened */

    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {

/* L2410: */

/* L2420: */

/* L2430: */

/* L2440: */

/* L2450: */

	if (labs[i__] >= 0 && labs[i__] <= 9) {
	    io___625.ciunit = iun;
	    s_wsfe(&io___625);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&labs[i__], (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&x[i__], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&y[i__], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

	if (labs[i__] >= 10 && labs[i__] <= 99) {
	    io___626.ciunit = iun;
	    s_wsfe(&io___626);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&labs[i__], (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&x[i__], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&y[i__], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

	if (labs[i__] >= 100 && labs[i__] <= 999) {
	    io___627.ciunit = iun;
	    s_wsfe(&io___627);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&labs[i__], (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&x[i__], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&y[i__], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

	if (labs[i__] >= 1000 && labs[i__] <= 9999) {
	    io___628.ciunit = iun;
	    s_wsfe(&io___628);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&labs[i__], (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&x[i__], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&y[i__], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

	if (labs[i__] >= 10000 && labs[i__] <= 99999) {
	    io___629.ciunit = iun;
	    s_wsfe(&io___629);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&labs[i__], (ftnlen)sizeof(integer));
	    do_fio(&c__1, quo, (ftnlen)1);
	    do_fio(&c__1, (char *)&x[i__], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&y[i__], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

/* L2600: */
    }
    qua_labels_conn__(iw);
    cl__1.cerr = 0;
    cl__1.cunit = iun;
    cl__1.csta = 0;
    f_clos(&cl__1);

    return 0;
} /* qua_labels_int__ */

#undef anum8
#undef anum1
#undef file8
#undef file1







/* Subroutine */ int quamesslen_(char *mes, integer *nchar, char *line, 
	ftnlen mes_len, ftnlen line_len)
{
    /* Initialized data */

    static char ast[1] = "*";

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, i1;

    /* Parameter adjustments */
    --line;
    --mes;

    /* Function Body */

/*         DETERMINE THE LENGTH OF THE MESSAGE */

    i__ = 0;
    for (i__ = 1; i__ <= 10000; ++i__) {
	if (*(unsigned char *)&mes[i__] == *(unsigned char *)&ast[0]) {
	    goto L1600;
	}
	i1 = i__;
/* L1400: */
    }
L1600:

    *nchar = i1;
    i__1 = *nchar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*(unsigned char *)&line[i__] = *(unsigned char *)&mes[i__];
/* L1800: */
    }
    return 0;
} /* quamesslen_ */






/* Subroutine */ int exograph2d_(integer *iw, doublereal *ts, integer *n, 
	doublereal *vals, integer *isub, char *title, ftnlen title_len)
{
    /* Initialized data */

    static char blank[1] = " ";
    static char quo[1] = "\"";

    /* Format strings */
    static char fmt_2000[] = "(1a8)";
    static char fmt_2250[] = "(\002   # set terminal postscript\002,/,\002  "
	    " # set output \"plot.ps\"\002)";
    static char fmt_2270[] = "(\002  set title \002,80a1)";
    static char fmt_2280[] = "(\002   show title\002)";
    static char fmt_2400[] = "(i6)";
    static char fmt_2800[] = "(\002splot \002,\002\"\002,1a8,\002\"    "
	    " \002,\002notitle  with lines\002)";
    static char fmt_3000[] = "(2x,e11.5,2x,e11.5,2x,e11.5)";
    static char fmt_3100[] = "(20x)";

    /* System generated locals */
    integer vals_dim1, vals_offset, i__1, i__2, i__3, i__4;
    olist o__1;
    cllist cl__1;
    static char equiv_0[8], equiv_1[8];

    /* Builtin functions */
    integer f_open(olist *), s_wsfe(cilist *), e_wsfe(void), do_fio(integer *,
	     char *, ftnlen), s_wsfi(icilist *), e_wsfi(void), s_rsfi(icilist 
	    *), e_rsfi(void), f_clos(cllist *);

    /* Local variables */
    static integer i__, j, ii;
    extern /* Subroutine */ int quamesslen_(char *, integer *, char *, ftnlen,
	     ftnlen);
    static integer iun, iss, iun2;
    static char line[1*82];
    static integer iun22;
    extern /* Subroutine */ int qua_filename__(integer *, char *, ftnlen);
#define file1 (equiv_0)
#define file8 (equiv_0)
#define anum1 (equiv_1)
#define anum8 (equiv_1)
    static integer nchar;
    static char dummy[8];

    /* Fortran I/O blocks */
    static cilist io___640 = { 0, 0, 0, fmt_2250, 0 };
    static cilist io___643 = { 0, 0, 0, fmt_2270, 0 };
    static cilist io___645 = { 0, 0, 0, fmt_2280, 0 };
    static icilist io___648 = { 0, dummy, 0, fmt_2400, 8, 1 };
    static icilist io___649 = { 0, dummy, 0, fmt_2000, 8, 1 };
    static cilist io___650 = { 0, 0, 0, fmt_2800, 0 };
    static cilist io___655 = { 0, 0, 0, fmt_3000, 0 };
    static cilist io___656 = { 0, 0, 0, fmt_3100, 0 };


    /* Parameter adjustments */
    vals_dim1 = *n;
    vals_offset = 1 + vals_dim1;
    vals -= vals_offset;
    --ts;
    --title;

    /* Function Body */


/*        convert the user-specified Fortran unit number to */
/*        character format */

/* L2000: */

    qua_filename__(iw, file8, (ftnlen)8);

/*        open the fortran file with the unit 87 and name file8 */

    iun = 87;
    o__1.oerr = 0;
    o__1.ounit = iun;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

/* L2250: */

    io___640.ciunit = iun;
    s_wsfe(&io___640);
    e_wsfe();

/*        generate the title for the plot */

    *(unsigned char *)&line[0] = *(unsigned char *)&blank[0];
    *(unsigned char *)&line[1] = *(unsigned char *)&blank[0];
    *(unsigned char *)&line[2] = *(unsigned char *)&quo[0];

    quamesslen_(title + 1, &nchar, line + 3, (ftnlen)1, (ftnlen)1);

    *(unsigned char *)&line[nchar + 3] = *(unsigned char *)&quo[0];
/* L2270: */

    io___643.ciunit = iun;
    s_wsfe(&io___643);
    i__1 = nchar + 4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, line + (i__ - 1), (ftnlen)1);
    }
    e_wsfe();

/* L2280: */
    io___645.ciunit = iun;
    s_wsfe(&io___645);
    e_wsfe();


/*        write the instructions */

/* L2400: */
    iun2 = *iw + 100000;
    s_wsfi(&io___648);
    do_fio(&c__1, (char *)&iun2, (ftnlen)sizeof(integer));
    e_wsfi();
    s_rsfi(&io___649);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2600: */
    }

/* L2800: */
    io___650.ciunit = iun;
    s_wsfe(&io___650);
    do_fio(&c__1, file8, (ftnlen)8);
    e_wsfe();

/*       create trhe data file */


/*        write the data file to be plotted */

    iun22 = 88;
    iss = *isub;
    if (iss == 0) {
	iss = 1;
    }

    o__1.oerr = 0;
    o__1.ounit = iun22;
    o__1.ofnmlen = 8;
    o__1.ofnm = file8;
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

    i__1 = *n;
    i__2 = iss;
    for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
	i__3 = *n;
	i__4 = iss;
	for (j = 1; i__4 < 0 ? j >= i__3 : j <= i__3; j += i__4) {

	    ++ii;
	    io___655.ciunit = iun22;
	    s_wsfe(&io___655);
	    do_fio(&c__1, (char *)&ts[i__], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ts[j], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&vals[i__ + j * vals_dim1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();

/* L3100: */

/* L3200: */
	}

	io___656.ciunit = iun22;
	s_wsfe(&io___656);
	e_wsfe();
/* L3400: */
    }

    cl__1.cerr = 0;
    cl__1.cunit = iun22;
    cl__1.csta = 0;
    f_clos(&cl__1);

    return 0;
} /* exograph2d_ */

#undef anum8
#undef anum1
#undef file8
#undef file1







/* Subroutine */ int qua_filename__(integer *iw, char *file88, ftnlen 
	file88_len)
{
    /* Initialized data */

    static char gn[1*2] = "g" "n";

    /* Format strings */
    static char fmt_1100[] = "(i1)";
    static char fmt_1200[] = "(i2)";
    static char fmt_1300[] = "(i3)";
    static char fmt_1400[] = "(i4)";
    static char fmt_2000[] = "(1a8)";

    /* System generated locals */
    static char equiv_0[8], equiv_1[8];

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_rsfi(icilist *), e_rsfi(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
#define file1 (equiv_0)
#define file8 (equiv_0)
#define anum1 (equiv_1)
#define anum8 (equiv_1)
    static char dummy[8];

    /* Fortran I/O blocks */
    static icilist io___663 = { 0, dummy, 0, fmt_1100, 8, 1 };
    static icilist io___664 = { 0, dummy, 0, fmt_1200, 8, 1 };
    static icilist io___665 = { 0, dummy, 0, fmt_1300, 8, 1 };
    static icilist io___666 = { 0, dummy, 0, fmt_1400, 8, 1 };
    static icilist io___667 = { 0, dummy, 0, fmt_2000, 8, 1 };




/*        convert the user-specified Fortran unit number to */
/*        character format */

    if (*iw >= 0 && *iw <= 9) {
	s_wsfi(&io___663);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 10 && *iw <= 99) {
	s_wsfi(&io___664);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 100 && *iw <= 999) {
	s_wsfi(&io___665);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

    if (*iw >= 1000 && *iw <= 9999) {
	s_wsfi(&io___666);
	do_fio(&c__1, (char *)&(*iw), (ftnlen)sizeof(integer));
	e_wsfi();
    }

/* L2000: */
    s_rsfi(&io___667);
    do_fio(&c__1, anum8, (ftnlen)8);
    e_rsfi();

/*        construct the file name on which the Gnuplot instructions */
/*        are to be written */

    *(unsigned char *)&file1[0] = *(unsigned char *)&gn[0];
    *(unsigned char *)&file1[1] = *(unsigned char *)&gn[1];
    for (i__ = 1; i__ <= 6; ++i__) {
	*(unsigned char *)&file1[i__ + 1] = *(unsigned char *)&anum1[i__ - 1];
/* L2200: */
    }

    s_copy(file88, file8, (ftnlen)8, (ftnlen)8);

    return 0;
} /* qua_filename__ */

#undef anum8
#undef anum1
#undef file8
#undef file1


