#ifndef SMOOTHING_FILTER_HPP
#define SMOOTHING_FILTER_HPP

class SmoothingFilter {
  /*CLASS: SMOOTHING FILTER
    This class takes as input a sample and outputs a filtered
    sample taking into account internal parameters:
    
    @m_initial_sample
    @m_current_sample
    @m_next_cnt
    @m_current_cnt
   
   */
public: //functions
  SmoothingFilter();
  ~SmoothingFilter();
  unsigned int smooth(unsigned int current_sample);
  unsigned int getCurrentSample();
  unsigned int getInitialSample();
  unsigned int getCurrentCnt();
  unsigned int getNextCnt();
  bool getHoldParam();
private: //Variables
  unsigned int m_initial_sample;
  unsigned int m_current_sample;
  unsigned int m_current_cnt;
  unsigned int m_next_cnt;
  bool m_hold;
  bool m_first_sample;
};

#endif
