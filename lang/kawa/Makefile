PORTNAME=	kawa
PORTVERSION=	3.1.1
PORTREVISION=	1
CATEGORIES=	lang scheme java
MASTER_SITES=	GNU

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Java-based Scheme implementation
WWW=		https://www.gnu.org/software/kawa/

LICENSE=	MIT

USES=		gmake groff java readline

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-kawa-frontend \
		--with-java-source=${JAVA_PORT_VERSION}
CONFIGURE_ENV=	JAVA="${JAVA}" JAVAC="${JAVAC}"
MAKE_ARGS=	JAR="${JAR}" READLINE_LIB_PATH="-L${LOCALBASE}/lib"
MAKE_ENV=	JAVA_TOOL_OPTIONS=-Dfile.encoding=UTF8
TEST_TARGET=	check
TEST_ARGS=	# must be empty, otherwise tests fail
TEST_ENV=	# must be empty, otherwise tests fail

MAKE_JOBS_UNSAFE=yes

INFO=		kawa
PLIST_FILES=	bin/kawa bin/qexo \
		share/kawa/bin/kawa share/kawa/lib/kawa.jar \
		share/man/man1/kawa.1.gz share/man/man1/qexo.1.gz \

post-patch:
	@${REINPLACE_CMD} -e '/life-grid.log$$/s,>&,>,' \
		${WRKSRC}/testsuite/Makefile.in

.include <bsd.port.mk>
