PORTNAME=	c7
PORTVERSION=	${LINUX_DIST_VER}
PORTREVISION=	5
CATEGORIES=	emulators linux
PKGNAMEPREFIX=	linux_base-
EXTRACT_ONLY=	${DISTFILES:N*${SRC_SUFX}*:Nfilesystem-*:C/:[^:]+$//}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Base set of packages needed in Linux mode (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LINUX=	# empty
USE_LINUX_RPM=	yes

# lib64/gconv/ stuff that is loaded dynamically and has rpath
NO_SHLIB_REQUIRES_GLOB=	libCNS.so* libGB.so* libISOIR165.so* \
			libJIS.so* libJISX0213.so* libKSC.so*

BIN_DISTNAMES=	bash-4.2.46-35.el7_9 \
		bzip2-1.0.6-13.el7 \
		centos-release-7-9.2009.2.el7.centos \
		coreutils-8.22-24.el7_9.2 \
		diffutils-3.3-6.el7_9 \
		e2fsprogs-1.42.9-19.el7 \
		filesystem-3.2-25.el7 \
		findutils-4.5.11-6.el7 \
		gawk-4.0.2-4.el7_3.1 \
		glibc-common-${GLIBC_VER} \
		grep-2.20-3.el7 \
		info-5.1-5.el7 \
		keyutils-1.5.8-3.el7 \
		less-458-10.el7_9 \
		ncurses-5.9-14.20130511.el7_4 \
		sed-4.2.2-7.el7 \
		setserial-2.17-33.el7 \
		which-2.20-7.el7
LIB_DISTNAMES=	audit-libs-2.8.5-4.el7 \
		bzip2-libs-1.0.6-13.el7 \
		compat-db47-4.7.25-28.el7 \
		e2fsprogs-libs-1.42.9-19.el7 \
		gamin-0.1.10-16.el7 \
		gdbm-1.10-8.el7 \
		glib2-2.56.1-9.el7_9 \
		glibc-${GLIBC_VER} \
		gmp-6.0.0-15.el7 \
		keyutils-libs-1.5.8-3.el7 \
		krb5-libs-1.15.1-55.el7_9 \
		libacl-2.2.51-15.el7 \
		libattr-2.4.46-13.el7 \
		libblkid-2.23.2-65.el7_9.1 \
		libcap-2.22-11.el7 \
		libcap-ng-0.7.5-4.el7 \
		libcom_err-1.42.9-19.el7 \
		libdb-5.3.21-25.el7 \
		libffi-3.0.13-19.el7 \
		libgcc-4.8.5-44.el7 \
		libidn-1.28-4.el7 \
		libmount-2.23.2-65.el7_9.1 \
		libselinux-2.5-15.el7 \
		libsepol-2.5-10.el7 \
		libstdc++-4.8.5-44.el7 \
		libuuid-2.23.2-65.el7_9.1 \
		libverto-0.2.5-4.el7 \
		mpfr-3.1.1-4.el7 \
		ncurses-libs-5.9-14.20130511.el7_4 \
		nss-softokn-freebl-3.90.0-6.el7_9 \
		openssl-libs-1.0.2k-26.el7_9 \
		pcre-8.32-17.el7 \
		popt-1.13-16.el7 \
		readline-6.2-11.el7 \
		slang-2.2.4-11.el7 \
		util-linux-2.23.2-65.el7_9.1 \
		xz-libs-5.2.2-2.el7_9 \
		zlib-1.2.7-21.el7_9

LIB_DISTNAMES_aarch64=	redhat-lsb-core-4.1-27.el7.1

LIB_DISTNAMES_amd64=	compat-libstdc++-33-3.2.3-72.el7 \
		redhat-lsb-core-4.1-27.el7.centos.1

LIB_DISTNAMES_i386=	compat-libstdc++-33-3.2.3-72.el7 \
		redhat-lsb-core-4.1-27.el7.centos.1

SHARE_DISTNAMES=basesystem-10.0-7.el7.centos \
		ncurses-base-5.9-14.20130511.el7_4 \
		setup-2.8.71-11.el7
SRC_DISTFILES=	acl-2.2.51-15.el7${SRC_SUFX}:SOURCE \
		attr-2.4.46-13.el7${SRC_SUFX}:SOURCE \
		audit-2.8.5-4.el7${SRC_SUFX}:SOURCE \
		basesystem-10.0-7.el7.centos${SRC_SUFX}:SOURCE \
		bash-4.2.46-35.el7_9${SRC_SUFX}:SOURCE \
		bzip2-1.0.6-13.el7${SRC_SUFX}:SOURCE \
		centos-release-7-9.2009.2.el7.centos${SRC_SUFX}:SOURCE \
		compat-db-4.7.25-28.el7${SRC_SUFX}:SOURCE \
		compat-gcc-32-3.2.3-72.el7${SRC_SUFX}:SOURCE \
		coreutils-8.22-24.el7_9.2${SRC_SUFX}:SOURCE \
		diffutils-3.3-6.el7_9${SRC_SUFX}:SOURCE \
		e2fsprogs-1.42.9-19.el7${SRC_SUFX}:SOURCE \
		filesystem-3.2-25.el7${SRC_SUFX}:SOURCE \
		findutils-4.5.11-6.el7${SRC_SUFX}:SOURCE \
		gamin-0.1.10-16.el7${SRC_SUFX}:SOURCE \
		gawk-4.0.2-4.el7_3.1${SRC_SUFX}:SOURCE \
		gcc-4.8.5-44.el7${SRC_SUFX}:SOURCE \
		gdbm-1.10-8.el7${SRC_SUFX}:SOURCE \
		glib2-2.56.1-9.el7_9${SRC_SUFX}:SOURCE \
		glibc-${GLIBC_VER}${SRC_SUFX}:amd64 \
		gmp-6.0.0-15.el7${SRC_SUFX}:SOURCE \
		grep-2.20-3.el7${SRC_SUFX}:SOURCE \
		keyutils-1.5.8-3.el7${SRC_SUFX}:SOURCE \
		krb5-1.15.1-55.el7_9${SRC_SUFX}:SOURCE \
		less-458-10.el7_9${SRC_SUFX}:SOURCE \
		libcap-2.22-11.el7${SRC_SUFX}:SOURCE \
		libcap-ng-0.7.5-4.el7${SRC_SUFX}:SOURCE \
		libdb-5.3.21-25.el7${SRC_SUFX}:SOURCE \
		libffi-3.0.13-19.el7${SRC_SUFX}:SOURCE \
		libidn-1.28-4.el7${SRC_SUFX}:SOURCE \
		libselinux-2.5-15.el7${SRC_SUFX}:SOURCE \
		libsepol-2.5-10.el7${SRC_SUFX}:SOURCE \
		mpfr-3.1.1-4.el7${SRC_SUFX}:SOURCE \
		ncurses-5.9-14.20130511.el7_4${SRC_SUFX}:SOURCE \
		nss-softokn-3.90.0-6.el7_9${SRC_SUFX}:SOURCE \
		openssl-1.0.2k-26.el7_9${SRC_SUFX}:SOURCE \
		pcre-8.32-17.el7${SRC_SUFX}:SOURCE \
		popt-1.13-16.el7${SRC_SUFX}:SOURCE \
		readline-6.2-11.el7${SRC_SUFX}:SOURCE \
		redhat-lsb-4.1-27.el7.centos.1${SRC_SUFX}:SOURCE \
		sed-4.2.2-7.el7${SRC_SUFX}:SOURCE \
		setserial-2.17-33.el7${SRC_SUFX}:SOURCE \
		setup-2.8.71-11.el7${SRC_SUFX}:SOURCE \
		slang-2.2.4-11.el7${SRC_SUFX}:SOURCE \
		texinfo-5.1-5.el7${SRC_SUFX}:SOURCE \
		util-linux-2.23.2-65.el7_9.1${SRC_SUFX}:SOURCE \
		which-2.20-7.el7${SRC_SUFX}:SOURCE \
		xz-5.2.2-2.el7_9${SRC_SUFX}:SOURCE \
		zlib-1.2.7-21.el7_9${SRC_SUFX}:SOURCE

PLIST_SUB=	LINUXBASE=${LINUXBASE} SYSCTLMIB=${SYSCTLMIB}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

REMOVE_DIRS=	boot etc/pam.d home media mnt proc root run sys tmp var/log \
		var/tmp
REMOVE_FILES=	bin/chfn bin/chsh bin/findmnt bin/login bin/lsblk bin/lscpu \
		bin/lsipc bin/lslogins bin/lsmem bin/lsns bin/script \
		bin/setpriv bin/su \
		etc/exports etc/group etc/gshadow etc/motd \
		etc/passwd etc/printcap etc/protocols etc/services etc/shadow \
		sbin/clock sbin/debugfs sbin/hwclock sbin/runuser sbin/zramctl

.include <bsd.port.options.mk>

GLIBC_VER=	2.17-326.el7_9.3
PLIST_SUB+=	NEWGLIBC=""

.if ${ARCH} == aarch64 || ${ARCH} == amd64
SYSCTLMIB=	kern.features.linux64
.else
SYSCTLMIB=	compat.linux.osrelease
.endif

post-extract:
# These directories become symbolic links when the filesystem distfile is
# extracted.  Other distfiles cannot be extracted when these are links so the
# filesystem distfile must be extracted last.
.for d in bin lib lib64 sbin
	@(cd ${WRKSRC} && if [ -e ${d} -a ! -L ${d} ]; then \
		${FIND} ${d} | ${CPIO} -dumpl --quiet usr && ${RM} -r ${d}; fi)
.endfor
	@(cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/filesystem-3.2-25.el7${EXTRACT_SUFX_${ARCH}} \
		${EXTRACT_AFTER_ARGS})
.if ${ARCH} == i386
	@${CHMOD} u+w ${WRKSRC}/usr/lib/pm-utils
.elif ${ARCH} == aarch64 || ${ARCH} == amd64
	@${CHMOD} u+w ${WRKSRC}/usr/lib64/pm-utils
.endif

post-patch:
	@${RM} -r ${REMOVE_DIRS:S|^|${WRKSRC}/|}
	@${RM} ${REMOVE_FILES:S|^|${WRKSRC}/|}
	@${FIND} ${WRKSRC}/usr -type d -empty -not -path '*/lib*/gio/*' -delete
.if ${ARCH} == amd64  ||  ${ARCH} == i386
	@${BRANDELF} -t Linux ${WRKSRC}/usr/lib/ld-2.17.so
.endif
.if ${ARCH} == aarch64 || ${ARCH} == amd64
	@${BRANDELF} -t Linux ${WRKSRC}/usr/lib64/ld-2.17.so
.endif

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/krb5.conf \
		${STAGEDIR}${PREFIX}/etc/krb5.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/nsswitch.conf \
		${STAGEDIR}${PREFIX}/etc/nsswitch.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/usr/lib/locale/locale-archive.tmpl \
		${STAGEDIR}${PREFIX}/usr/lib/locale/locale-archive
	${LN} -sf "../proc/self/mounts" ${STAGEDIR}${PREFIX}/etc/mtab
	${LN} -sf ${LOCALBASE}/share/icons ${STAGEDIR}${PREFIX}/usr/share/icons
	${LN} -sf /var/run ${STAGEDIR}${PREFIX}/run
	${LN} -sf /var/tmp ${STAGEDIR}${PREFIX}/usr/tmp

.include <bsd.port.mk>
