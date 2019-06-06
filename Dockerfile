FROM zerof/lenny32

RUN apt-get install libmysqlclient15-dev gcc make --force-yes -y

ADD ./code /code/

WORKDIR /code

RUN make
