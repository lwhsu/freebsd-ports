PORTNAME=	vobject
PORTVERSION=	0.9.6.1
PORTREVISION=	3
CATEGORIES=	deskutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	ICalendar library
WWW=		https://eventable.github.io/vobject/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-2.0.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.4.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	eventable

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} tests.py

.include <bsd.port.mk>
