dnl $Id$
dnl config.m4 for extension yal

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(yal, for yal support,
dnl Make sure that the comment is aligned:
dnl [  --with-yal             Include yal support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(yal, whether to enable yal support,
Make sure that the comment is aligned:
[  --enable-yal           Enable yal support])

if test "$PHP_YAL" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-yal -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/yal.h"  # you most likely want to change this
  dnl if test -r $PHP_YAL/$SEARCH_FOR; then # path given as parameter
  dnl   YAL_DIR=$PHP_YAL
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for yal files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       YAL_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$YAL_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the yal distribution])
  dnl fi

  dnl # --with-yal -> add include path
  dnl PHP_ADD_INCLUDE($YAL_DIR/include)

  dnl # --with-yal -> check for lib and symbol presence
  dnl LIBNAME=yal # you may want to change this
  dnl LIBSYMBOL=yal # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $YAL_DIR/lib, YAL_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_YALLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong yal lib version or lib not found])
  dnl ],[
  dnl   -L$YAL_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(YAL_SHARED_LIBADD)

  PHP_NEW_EXTENSION(yal,                    
      yal.c                                           \
      yal_acl.c                                       \
      acl/yal_acl_acl_interface.c                     \
      acl/yal_acl_role_role_interface.c               \
      acl/yal_acl_role_registery.c                    \
      acl/yal_acl_resource_resource_interface.c       \
      acl/yal_acl_role_generic_role.c,
      $ext_shared)
fi
