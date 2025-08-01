# pkg-help formatted with fmt 59 63

PORTNAME=	bind
DISTVERSION=	9.20.10
.if defined(BIND_TOOLS_SLAVE)
# dns/bind-tools here
PORTREVISION=	1
.else
# XXX: correct version
# dns/bind920 here
PORTREVISION=	2
.endif
CATEGORIES=	dns net
MASTER_SITES=	ISC/bind9/${DISTVERSION}
.if defined(BIND_TOOLS_SLAVE)
PKGNAMESUFFIX=	-tools
.else
PKGNAMESUFFIX=	920
.endif

MAINTAINER=	mat@FreeBSD.org
.if defined(BIND_TOOLS_SLAVE)
COMMENT=	Command line tools from BIND: delv, dig, host, nslookup...
.else
COMMENT=	BIND DNS suite with updated DNSSEC and DNS64
.endif
WWW=		https://www.isc.org/bind/

# Uncomment when bind922 comes of age. +3 years if ESV, +1year otherwise, see
# https://kb.isc.org/docs/aa-00896
# DEPRECATED=	End of life, please migrate to a newer version of BIND9
# EXPIRATION_DATE=	XXX-12-31

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libnghttp2.so:www/libnghttp2 \
		liburcu.so:sysutils/liburcu \
		libuv.so:devel/libuv

.if !defined(BIND_TOOLS_SLAVE)
RUN_DEPENDS=	bind-tools>0:dns/bind-tools
.endif

USES=		autoreconf compiler:c11 cpe gnome libedit libtool pkgconfig ssl \
		tar:xz

CPE_VENDOR=	isc
CPE_VERSION=	${DISTVERSION:C/-.*//}
.if ${DISTVERSION:M*-*}
CPE_UPDATE=	${DISTVERSION:C/.*-//:tl}
.endif

.if !defined(BIND_TOOLS_SLAVE)
USE_RC_SUBR=	named
.endif # !BIND_TOOLS_SLAVE

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-dnsrps \
		--localstatedir=/var \
		--sysconfdir=${ETCDIR} \
		--with-openssl=${OPENSSLBASE} \
		--with-readline=libedit

MAKE_JOBS_UNSAFE=	yes

.if !defined(BIND_TOOLS_SLAVE)
CONFLICTS=	bind9-devel bind918
.endif # !BIND_TOOLS_SLAVE

ETCDIR=		${PREFIX}/etc/namedb

# FIXME: figure out why build fails if enabled
CONFIGURE_ARGS+=	--disable-tracing

.if defined(BIND_TOOLS_SLAVE)
EXTRA_PATCHES=		${PATCHDIR}/extrapatch-bind-tools
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/bind-tools
.else
SUB_FILES=		named.conf pkg-message
EXTRA_PATCHES=		${PATCHDIR}/extrapatch-no-bind-tools

PORTDOCS=	*
.endif # BIND_TOOLS_SLAVE

OPTIONS_DEFINE=		DNSTAP DOCS FIXED_RRSET GEOIP IDN LARGE_FILE LMDB \
			OVERRIDECACHE QUERYTRACE START_LATE TCP_FASTOPEN
OPTIONS_DEFAULT=	DNSTAP GSSAPI_NONE IDN LMDB STATS_JSON STATS_XML \
			TCP_FASTOPEN

OPTIONS_GROUP=		STATS
OPTIONS_GROUP_STATS=	STATS_JSON STATS_XML

OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE

.if defined(BIND_TOOLS_SLAVE)
OPTIONS_EXCLUDE=	DOCS GEOIP LMDB OVERRIDECACHE QUERYTRACE START_LATE \
			STATS_JSON STATS_XML TCP_FASTOPEN
.endif # BIND_TOOLS_SLAVE

OPTIONS_SUB=	yes

DNSTAP_DESC=		Provides fast passive logging of DNS messages
FIXED_RRSET_DESC=	Enable fixed rrset ordering
GSSAPI_BASE_DESC=	Using Heimdal in base (nsupdate is broken)
GSSAPI_HEIMDAL_DESC=	Using security/heimdal (nsupdate is broken)
GSSAPI_MIT_DESC=	Using security/krb5
GSSAPI_NONE_DESC=	Disable
LARGE_FILE_DESC=	64-bit file support
LMDB_DESC=		Use LMDB for zone management
OVERRIDECACHE_DESC=	Use the override-cache patch
QUERYTRACE_DESC=	Enable the very verbose query tracelogging
START_LATE_DESC=	Start BIND late in the boot process (see help)
STATS_DESC=		Statistics channels
STATS_JSON_DESC=	Enable JSON statistics channel
STATS_XML_DESC=		Enable XML statistics channel
TCP_FASTOPEN_DESC=	RFC 7413 support

DNSTAP_LIB_DEPENDS=		libfstrm.so:devel/fstrm \
				libprotobuf-c.so:devel/protobuf-c
DNSTAP_CONFIGURE_ENABLE=	dnstap

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
			sphinx-build:textproc/py-sphinx
DOCS_USES=		gmake python:env
DOCS_ALL_TARGET=	all html

FIXED_RRSET_CONFIGURE_ENABLE=	fixed-rrset

GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
GEOIP_CONFIGURE_ENABLE=	geoip
GEOIP_CONFIGURE_WITH=	maxminddb

GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-gssapi="${KRB5CONFIG}"

GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-gssapi="${KRB5CONFIG}"

GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-gssapi="${KRB5CONFIG}"

GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi

IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2
IDN_USES=		iconv
IDN_CONFIGURE_ON=	${ICONV_CONFIGURE_BASE} \
			--with-libidn2=${LOCALBASE}
IDN_CONFIGURE_OFF=	--without-libidn2

LARGE_FILE_CONFIGURE_ENABLE=	largefile

LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb
LMDB_CONFIGURE_WITH=	lmdb=${LOCALBASE}

OVERRIDECACHE_EXTRA_PATCHES=	${FILESDIR}/extrapatch-bind-min-override-ttl

QUERYTRACE_CONFIGURE_ENABLE=	querytrace

START_LATE_SUB_LIST=		NAMED_BEFORE="LOGIN" \
				NAMED_REQUIRE="SERVERS cleanvar"
START_LATE_SUB_LIST_OFF=	NAMED_BEFORE="SERVERS" \
				NAMED_REQUIRE="NETWORKING ldconfig syslogd"

STATS_JSON_LIB_DEPENDS=		libjson-c.so:devel/json-c
STATS_JSON_CONFIGURE_WITH=	json-c
STATS_JSON_LDFLAGS=		-L${LOCALBASE}/lib -ljson-c

STATS_XML_USE=			GNOME=libxml2
STATS_XML_CONFIGURE_WITH=	libxml2

TCP_FASTOPEN_CONFIGURE_ENABLE=	tcp-fastopen

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-developer
USES+=			perl5
USE_PERL5=		build
BUILD_DEPENDS+=		cmocka>0:sysutils/cmocka
.endif

.if !${PORT_OPTIONS:MDOCS}
CONFIGURE_ENV+=	ac_cv_path_SPHINX_BUILD=
.endif

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
SUB_LIST+=	ENGINES=/usr/lib/engines
.else
SUB_LIST+=	ENGINES=${LOCALBASE}/lib/engines
.endif

post-patch:
.for FILE in check/named-checkconf.rst named/named.rst nsupdate/nsupdate.rst \
	rndc/rndc.rst
	@${REINPLACE_CMD} -e 's#/etc/named.conf#${ETCDIR}/named.conf#g' \
		-e 's#/etc/rndc.conf#${ETCDIR}/rndc.conf#g' \
		-e "s#/var\/run\/named\/named.pid#/var/run/named/pid#" \
		${WRKSRC}/bin/${FILE}
.endfor

.if !defined(BIND_TOOLS_SLAVE)
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mtree
	${MKDIR} ${STAGEDIR}${ETCDIR}
.  for i in dynamic primary secondary working
	@${MKDIR} ${STAGEDIR}${ETCDIR}/$i
.  endfor
	${INSTALL_DATA} ${WRKDIR}/named.conf ${STAGEDIR}${ETCDIR}/named.conf.sample
	${INSTALL_DATA} ${FILESDIR}/named.root ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/empty.db ${STAGEDIR}${ETCDIR}/primary
	${INSTALL_DATA} ${FILESDIR}/localhost-forward.db ${STAGEDIR}${ETCDIR}/primary
	${INSTALL_DATA} ${FILESDIR}/localhost-reverse.db ${STAGEDIR}${ETCDIR}/primary
	${INSTALL_DATA} ${FILESDIR}/BIND.chroot.dist ${STAGEDIR}${PREFIX}/etc/mtree/BIND.chroot.dist.sample
	${INSTALL_DATA} ${FILESDIR}/BIND.chroot.local.dist ${STAGEDIR}${PREFIX}/etc/mtree/BIND.chroot.local.dist.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/arm/_build/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/arm
.else

do-install:
	for dir in bin lib doc/man; do \
		(cd ${INSTALL_WRKSRC}/$$dir && ${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}) ; \
	done
	@${RM} -r ${STAGEDIR}${PREFIX}/include

.endif # BIND_TOOLS_SLAVE

.include <bsd.port.post.mk>
