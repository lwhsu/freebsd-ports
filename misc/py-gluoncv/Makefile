PORTNAME=	gluoncv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gluon CV toolkit for state-of-the-art deep learning in computer vision
WWW=		https://gluon-cv.mxnet.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expiring misc/py-mxnet
EXPIRATION_DATE=2025-06-01

PY_DEPENDS=	${PYNUMPY} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mxnet>0:misc/py-mxnet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portalocker>0:devel/py-portalocker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		compiler:c11 python localbase
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
GH_PROJECT=	gluon-cv
USE_PYTHON=	distutils cython autoplist

PYDISTUTILS_BUILDARGS=		--with-cython
PYDISTUTILS_INSTALLARGS=	--with-cython

post-patch: # https://github.com/dmlc/gluon-cv/issues/1095
	@truncate -s 0 ${WRKSRC}/README.md

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -name "*.so" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
