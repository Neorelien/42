FROM alpine:latest


ADD		srcs/ /root/

RUN		mkdir -p /srv/www/wordpress

RUN		apk add wget php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session

RUN		wget http://fr.wordpress.org/latest-fr_FR.tar.gz -P /tmp	\
		&& tar xzf /tmp/latest-fr_FR.tar.gz -C /srv/www/wordpress

# port listening
EXPOSE 5050

#scripts
#RUN mkdir /script 
#ADD ./srcs/init.sh /script/init.sh



CMD /root/init.sh && /bin/sh 
