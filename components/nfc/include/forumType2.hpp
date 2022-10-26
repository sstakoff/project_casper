#ifndef _FORUM_TYPE_2_H_
#define _FORUM_TYPE_2_H_

class ForumType2Tag {
  public:
    ForumType2Tag();
    ~ForumType2Tag();

    void setTextRecord(const char *text);
    const uint8_t *readAddress(uint8_t addr);
};


#endif