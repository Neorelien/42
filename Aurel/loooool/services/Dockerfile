FROM alpine:latest

#tools
RUN apk update
RUN apk add wget php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session


#wordpres install
RUN mkdir -p /www/
RUN wget http://fr.wordpress.org/latest-fr_FR.tar.gz -P /tmp
RUN tar xzf /tmp/latest-fr_FR.tar.gz -C /www/

# port listening
EXPOSE 5050

#scripts
#RUN mkdir /script 
#ADD ./srcs/init.sh /script/init.sh



CMD /bin/sh
