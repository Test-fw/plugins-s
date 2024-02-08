{# SPDX-License-Identifier: MIT #}
{# SPDX-FileCopyrightText: © 2021 CrowdSec <info@crowdsec.net> #}

<script>
    $( document ).ready(function() {
        var data_get_map = {'frm_GeneralSettings':"/api/crowdsec/general/get"};
        mapDataToFormUI(data_get_map).done(function(data){
            // place actions to run after load, for example update form styles.
        });

        // link save button to API set action
        $("#saveAct").click(function(){
            saveFormToEndpoint(url="/api/crowdsec/general/set",formid='frm_GeneralSettings',callback_ok=function(){
                $("#settingsSavedMsg").text("Saving settings....").removeClass("hidden");
                // action to run after successful save, for example reconfigure service.
                ajaxCall(url="/api/crowdsec/service/reload", sendData={},callback=function(data,status) {
                    $("#settingsSavedMsg").html(
                        '<i class="fa fa-check text-success"></i> Settings have been saved, services restarted.'
                    ).removeClass("hidden");
                });
            });
        });

        if(window.location.hash !== "") {
            $('a[href="' + window.location.hash + '"]').click()
        }
        $('.nav-tabs a').on('shown.bs.tab', function (e) {
            history.pushState(null, null, e.target.hash);
        });
    });
</script>

<style type="text/css">
#introduction a.btn-info {
  color: black;
  margin: 3px;
}

.tab-pane {
  margin: 10px;
}
</style>

<ul class="nav nav-tabs" role="tablist" id="maintabs" style="display: none;">
    <li><a data-toggle="tab" id="settings-tab" href="#settings"><b>Settings</b></a></li>
</ul>

<div class="content-box tab-content">

    <div id="settings" class="tab-pane fade active">
        <!-- <div class="alert alert-info active" role="alert" id="settingsSavedMsg"> -->
        </div>
        <div  class="col-md-12">
            {{ partial("layout_partials/base_form",['fields':generalForm,'id':'frm_GeneralSettings'])}}
        </div>

        <div class="col-md-12">
            <button class="btn btn-primary"  id="saveAct" type="button"><b>{{ lang._('Apply') }}</b></button>
        </div>
    </div>
</div>
