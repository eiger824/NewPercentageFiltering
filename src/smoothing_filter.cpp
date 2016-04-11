#include "smoothing_filter.hpp"

SmoothingFilter::SmoothingFilter():m_initial_sample(0),
				   m_current_sample(0),
				   m_current_cnt(0),
				   m_next_cnt(0),
				   m_hold(false),
				   m_first_sample(true) {
}

SmoothingFilter::~SmoothingFilter() {
}

unsigned int SmoothingFilter::getCurrentSample() {
  return m_current_sample;
}

unsigned int SmoothingFilter::getInitialSample() {
  return m_initial_sample;
}

unsigned int SmoothingFilter::getCurrentCnt() {
  return m_current_cnt;
}

unsigned int SmoothingFilter::getNextCnt() {
  return m_next_cnt;
}

bool SmoothingFilter::getHoldParam() {
  return m_hold;
}

unsigned int SmoothingFilter::smooth(unsigned int current_sample) {
  unsigned int tuned_sample;
  if (m_first_sample) {
    m_initial_sample = current_sample;
    m_first_sample = false;
  }

  tuned_sample = m_initial_sample;
  if (current_sample == m_initial_sample && m_hold == false) {
    ++m_current_cnt;
  } else if (current_sample < m_initial_sample) {
    if (current_sample != m_initial_sample) {
      ++m_next_cnt;
      tuned_sample = m_initial_sample;
    }
    m_hold = true;
    if (m_next_cnt > m_current_cnt) {
      tuned_sample = current_sample;
      m_current_cnt = 0;
      m_next_cnt = 0;
      m_hold = false;
      m_initial_sample = tuned_sample;
    } else {
      tuned_sample = m_initial_sample;
    }
    
  }
  return tuned_sample;
}
