/*
 *  git2r, R bindings to the libgit2 library.
 *  Copyright (C) 2013-2014 The git2r contributors
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License, version 2,
 *  as published by the Free Software Foundation.
 *
 *  git2r is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <Rdefines.h>
#include "git2r_tree.h"

/**
 * Init slots in S4 class git_tree
 *
 * @param source a tree
 * @param dest S4 class git_tree to initialize
 * @return void
 */
void init_tree(const git_tree *source, SEXP dest)
{
    int err;
    const git_oid *oid;
    char hex[GIT_OID_HEXSZ + 1];

    oid = git_tree_id(source);
    git_oid_tostr(hex, sizeof(hex), oid);
    SET_SLOT(dest,
             Rf_install("hex"),
             ScalarString(mkChar(hex)));
}