PORTNAME=	dipy
DISTVERSION=	1.10.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python toolbox for analysis of MR diffusion imaging
WWW=		https://dipy.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>0:devel/meson-python@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=3.1.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nibabel>=3.0.0:science/py-nibabel@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.8:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.30.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trx-python>=0.2.9:science/py-trx-python@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}statsmodels>0:math/py-statsmodels@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tables>0:devel/py-tables@${PY_FLAVOR} # "ml" extra dependencies, see dipy/info.py
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fury>0:graphics/py-fury@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} # "viz" extra dependencies, see dipy/info.py
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cvxpy>0:math/py-cvxpy@${PY_FLAVOR} # "doc" extra dependencies, see dipy/info.py

USES=		python shebangfix
USE_PYTHON=	concurrent cython3 pep517 pytest # autoplist is broken: it produces incorrect entries and unnecessary files are also placed under doc/

SHEBANG_GLOB=	*.sh *.py

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	# strip binaries
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/*/*.so
	# remove doc files
	@${RM} -rf ${STAGEDIR}${PREFIX}/doc

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} tools/ci/run_tests.sh

.include <bsd.port.mk>
