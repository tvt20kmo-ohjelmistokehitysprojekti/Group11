<?php

defined('BASEPATH') OR exit('No direct script access allowed');

require APPPATH . 'libraries/REST_Controller.php';

class Action extends REST_Controller {

    function __construct()
    {
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        parent::__construct();

        $this->load->model('Action_model');
    }

    public function index_get()
    {
        $id = $this->get('id');

        if ($id === NULL)
        {
            $Action=$this->Action_model->get_Action(NULL);

            if ($Action)
            {
                $this->response($Action, REST_Controller::HTTP_OK);
            }
            else
            {
                $this->response([
                    'status' => FALSE,
                    'message' => 'No action were found'
                ], REST_Controller::HTTP_NOT_FOUND);
            }
        }

        else {
            if ($id <= 0)
            {
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST);
            }

            $Action=$this->Action_model->get_Action($id);
            if (!empty($Action))
            {
                $this->set_response($Action, REST_Controller::HTTP_OK);
            }
            else
            {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'action could not be found'
                ], REST_Controller::HTTP_NOT_FOUND);
            }
        }

    }

    public function index_post()
    {
        $add_data=array(
          'idaccount'=>$this->post('idaccount'),
          'action'=>$this->post('action'),
          'action_time'=>$this->post('action_time'),
          'amount'=>$this->post('amount')
        );
        $insert_id=$this->Action_model->add_Action($add_data);
        if($insert_id)
        {
            $message = [
                'idaction' => $insert_id,
                'idaccount'=>$this->post('idaccount'),
                'action'=>$this->post('action'),
                'action_time'=>$this->post('action_time'),
                'amount'=>$this->post('amount'),
                'message' => 'Added a resource'
            ];
            $this->set_response($message, REST_Controller::HTTP_CREATED);
        }
        else
        {
            $this->response([
                'status' => FALSE,
                'message' => 'Can not add data'
            ], REST_Controller::HTTP_CONFLICT);
        }

    }
    public function index_put()
    {
        $id=$this->get('id');
        $update_data=array(
          'idaccount'=>$this->post('idaccount'),
          'action'=>$this->post('action'),
          'action_time'=>$this->post('action_time'),
          'amount'=>$this->post('amount')
        );
        $result=$this->Action_model->update_Action($id, $update_data);

        if($result)
        {
            $message = [
                'idaction' => $insert_id,
                'idaccount'=>$this->post('idaccount'),
                'action'=>$this->post('action'),
                'action_time'=>$this->post('action_time'),
                'amount'=>$this->post('amount'),
                'message' => 'Updates a resource'
            ];

            $this->set_response($message, REST_Controller::HTTP_CREATED);
        }
        else 
        {
            $this->response([
                'status' => FALSE,
                'message' => 'Can not update data'
            ], REST_Controller::HTTP_CONFLICT);
        }
    }

    public function index_delete()
    {
        $id = $this->get('id');

        if ($id <= 0)
        {
            $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST);
        }
        $result=$this->Action_model->delete_Action($id);
        if ($result)
        {
          $message = [
              'idaction' => $id,
              'message' => 'Deleted the resource'
          ];
          $this->set_response($message, REST_Controller::HTTP_OK);
        }
        else
        {
            $this->response([
                'status' => FALSE,
                'message' => 'Can not delete data'
            ], REST_Controller::HTTP_CONFLICT);
        }
    }



}