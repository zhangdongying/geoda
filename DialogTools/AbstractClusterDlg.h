/**
 * GeoDa TM, Copyright (C) 2011-2015 by Luc Anselin - all rights reserved
 *
 * This file is part of GeoDa.
 *
 * GeoDa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GeoDa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GEODA_CENTER_ABSTRACTCLUSTER_DLG_H___
#define __GEODA_CENTER_ABSTRACTCLUSTER_DLG_H___

#include <vector>
#include <map>
#include <wx/choice.h>
#include <wx/checklst.h>


#include "../FramesManager.h"
#include "../VarTools.h"

using namespace std;

class Project;
class TableInterface;
	
class AbstractClusterDlg : public wxDialog, public FramesManagerObserver
{
public:
    AbstractClusterDlg(wxFrame *parent, Project* project, wxString title);
    virtual ~AbstractClusterDlg();
    
    /** Implementation of FramesManagerObserver interface */
    virtual void update(FramesManager* o);
    
    
protected:
    wxFrame *parent;
    Project* project;
    TableInterface* table_int;
    FramesManager* frames_manager;
    
    int num_obs;
    std::vector<wxString> tm_strs;
    std::map<wxString, wxString> name_to_nm;
    std::map<wxString, int> name_to_tm_id;
    std::map<int, double> idx_sum;
    
    wxTextValidator validator;
    wxArrayString var_items;
   
    virtual bool Init();
    
    virtual double* GetWeights(int columns);
    
    virtual double GetMinBound();
   
    virtual double* GetBoundVals();
    
    // Input related
    wxListBox* combo_var;
    wxCheckBox* m_use_centroids;
    wxSlider* m_weight_centroids;
    wxTextCtrl* m_wc_txt;
    virtual void AddInputCtrls(wxPanel *panel, wxListBox** combo_var, wxCheckBox** m_use_centroids,wxSlider** m_weight_centroids, wxTextCtrl** m_wc_txt, wxBoxSizer* vbox);
    void OnUseCentroids(wxCommandEvent& event);
    void OnSlideWeight(wxCommandEvent& event);
    void InitVariableCombobox(wxListBox* var_box);
    
   
    // Minimum Bound related
    wxCheckBox* chk_floor;
    wxChoice* combo_floor;
    wxTextCtrl* txt_floor;
    wxTextCtrl* txt_floor_pct;
    wxSlider* slider_floor;
    virtual void AddMinBound(wxPanel *panel, wxCheckBox** chk_floor, wxChoice** combo_floor, wxTextCtrl** txt_floor, wxSlider** slider_floor, wxTextCtrl** txt_floor_pct,wxFlexGridSizer* gbox);
    virtual void  OnCheckMinBound(wxCommandEvent& event);
    virtual void  OnSelMinBound(wxCommandEvent& event);
    virtual void  OnTypeMinBound(wxCommandEvent& event);
    virtual void  OnSlideMinBound(wxCommandEvent& event);
};

#endif