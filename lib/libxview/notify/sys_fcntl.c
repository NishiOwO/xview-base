#ifndef	lint
#ifdef sccs
static char     sccsid[] = "@(#)sys_fcntl.c 20.13 93/06/28 Copyr 1985 Sun Micro";
#endif
#endif

/*
 *	(c) Copyright 1989 Sun Microsystems, Inc. Sun design patents 
 *	pending in the U.S. and foreign countries. See LEGAL NOTICE 
 *	file for terms of the license.
 */

/*
 * Sys_fcntl.c - Real system call to fcntl.
 */

#ifndef SVR4
#ifndef __linux__
#ifndef __NetBSD__
#include <syscall.h>
#endif
#else
#include "linux_select.h"
#endif
#else /* SVR4 */
#include <sys/syscall.h>
#endif /* SVR4 */
#include <xview_private/ntfy.h>

pkg_private int
notify_fcntl(fd, cmd, arg)
    int             fd, cmd, arg;
{
#if !defined(__linux__) && !defined(__NetBSD__)
    return (syscall(SYS_fcntl, fd, cmd, arg));
#else
#ifdef __GLIBC__
    return (__fcntl(fd, cmd, arg));
#else
#ifdef __NetBSD__
    return (fcntl(fd, cmd, arg));
#else
    return (sys_fcntl(fd, cmd, arg));
#endif
#endif
#endif
}
