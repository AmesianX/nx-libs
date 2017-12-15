/*
 * Copyright (c) 2006, Oracle and/or its affiliates. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
/*
 * Copyright © 2003 Keith Packard
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Keith Packard not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  Keith Packard makes no
 * representations about the suitability of this software for any purpose.  It
 * is provided "as is" without express or implied warranty.
 *
 * KEITH PACKARD DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL KEITH PACKARD BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file is a reduced version of the header file of
 * <X11/extensions/Xcomposite.h>
 *
 * This copy of code has been introduced to allow a clear namespace
 * separation between <X11/...> and <nx-X11/...> header files.
 *
 * This version of the Xcomposite library header file only contains symbols
 * required by nxagent and strictly avoids indirectly including
 * from an X11 library that is also shipped in nx-X11/lib/.
 *
 * When using <X11/extensions/Xcomposite.h> instead for inclusion in
 * nxagent, it will attempt pulling in the <X11/extensions/Xlib.h>.
 * However, the headers of the same name from <nx-X11/...> should be
 * used instead.
 *
 * FIXME: Once the nxagent Xserver starts using libX11 from X.Org, this
 * hack can be removed.
 *
 * 2016/04/07, Mike Gabriel <mike.gabriel@das-netzwerkteam.de>
 */

#ifndef _XCOMPOSITE_H_
#define _XCOMPOSITE_H_

#include <X11/extensions/composite.h>
#include <nx-X11/Xfuncproto.h>

/*
 * This revision number also appears in configure.ac, they have
 * to be manually synchronized
 */
#define XCOMPOSITE_MAJOR	COMPOSITE_MAJOR
#define XCOMPOSITE_MINOR	COMPOSITE_MINOR
#define XCOMPOSITE_REVISION	2
#define XCOMPOSITE_VERSION	((XCOMPOSITE_MAJOR * 10000) + (XCOMPOSITE_MINOR * 100) + (XCOMPOSITE_REVISION))

_XFUNCPROTOBEGIN

Bool XCompositeQueryExtension (Display *dpy,
                               int *event_base_return,
                               int *error_base_return);

Status XCompositeQueryVersion (Display *dpy,
                               int     *major_version_return,
                               int     *minor_version_return);

void
XCompositeRedirectWindow (Display *dpy, Window window, int update);

void
XCompositeRedirectSubwindows (Display *dpy, Window window, int update);

void
XCompositeUnredirectWindow (Display *dpy, Window window, int update);

void
XCompositeUnredirectSubwindows (Display *dpy, Window window, int update);

_XFUNCPROTOEND

#endif /* _XCOMPOSITE_H_ */
