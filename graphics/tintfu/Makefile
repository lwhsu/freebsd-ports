PORTNAME=	tintfu
PORTVERSION=	0.0.4
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GraphViz .dot file editor
WWW=		https://tintfu.sourceforge.net/

USES=		java

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${DISTNAME}.jar \
		bin/tintfu

SUB_FILES=	tintfu.sh
SUB_LIST=	DISTNAME=${DISTNAME}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/tintfu.sh ${STAGEDIR}${PREFIX}/bin/tintfu

.include <bsd.port.mk>
