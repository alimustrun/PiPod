//
// Created by fritsch on 13/02/18.
//

#ifndef PIPOD_SERVICE_H
#define PIPOD_SERVICE_H


class Service
{
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};


#endif //PIPOD_SERVICE_H
