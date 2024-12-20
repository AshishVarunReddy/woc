from setuptools import setup, find_packages

setup(
    name='liblearn',
    version='0.1.0',
    packages=find_packages(),
    install_requires=[
        'requests',
    ],
    author='Ashish',
    author_email='martiantorso@gmail.com',
    description='All machine learning models(except for reinforcement models).',
    long_description_content_type='text/markdown',
    #url='https://github.com/yourusername/my_package',
    classifiers=[
        'Programming Language :: Python :: 3',
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
    ],
    python_requires='>=3.6',
)
