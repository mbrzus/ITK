/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkWin32OutputWindow.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.

=========================================================================*/
#ifndef __itkWin32OutputWindow_h
#define __itkWin32OutputWindow_h

#ifdef _WIN32
#include "itkOutputWindow.h"
#include "itkObjectFactory.h"
#include "itkWindows.h"
namespace itk
{

/** \class Win32OutputWindow
 * \brief Collect error and debug messages on Win32-based systems.
 *
 * This class is used for error and debug message output on the windows
 * platform. It creates a read only EDIT control to display the
 * output. This class should not be used directly. It should
 * only be used through the interface of OutputWindow.  This class
 * only handles one output window per process.  If the window is destroyed,
 * the Object::GlobalWarningDisplayOff() function is called.  The
 * window is created the next time text is written to the window.
 */

class ITK_EXPORT Win32OutputWindow : public OutputWindow
{
public:
  /**
   * Standard "Self" typedef.
   */
  typedef Win32OutputWindow   Self;

  /**
   * Standard "Superclass" typedef.
   */
  typedef OutputWindow  Superclass;

  /** 
   * Smart pointer typedef support.
   */
  typedef SmartPointer<Self>  Pointer;
  typedef SmartPointer<const Self>  ConstPointer;

  /**
   * Method for creation through the object factory.
   */
  itkNewMacro(Self);

  /** 
   * Put the text into the display window.
   * Each new line is converted to a carriage return, new line.
   */ 
  virtual void DisplayText(const char*);

  static LRESULT APIENTRY WndProc(HWND hWnd, UINT message, 
                                  WPARAM wParam, LPARAM lParam);
protected: 
  Win32OutputWindow() {}
  virtual ~Win32OutputWindow() {}
  Win32OutputWindow(const Self&) {}
  void operator=(const Self&) {}
  
  void PromptText(const char* text);
  static void AddText(const char*);
  static int Initialize();
  static HWND m_OutputWindow;
};
 
  
} // end namespace itk
#endif  // end win32
#endif  //  __itkWin32OutputWindow_h
