PORTNAME=	python-crontab
PORTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Read and write crontab files using a direct API
WWW=		https://gitlab.com/doctormo/python-crontab

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-dateutil>=1.5:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}croniter>0:sysutils/py-croniter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cron-descriptor>0:sysutils/py-cron-descriptor@${PY_FLAVOR}

USES=		python shebangfix
SHEBANG_FILES=	${WRKSRC}/tests/data/crontest
USE_PYTHON=	autoplist distutils

USE_GITLAB=	yes
GL_ACCOUNT=	doctormo
GL_TAGNAME=	ba23056ddf1a00ecfd14b0a31c2e0cdad132f8d0

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
