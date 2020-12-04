<?php

defined('BASEPATH') OR exit('No direct script access allowed');

require APPPATH . 'libraries/REST_Controller.php';

class Card extends REST_Controller {

    function __construct()
    {
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        parent::__construct();

        $this->load->model('Card_model');
    }

    public function index_get()
    {
        $id = $this->get('id');

        if ($id === NULL)
        {
            $Card=$this->Card_model->get_Card(NULL);
            if ($Card)
            {
                $this->response($Card, REST_Controller::HTTP_OK);
            }
            else
            {
                $this->response([
                    'status' => FALSE,
                    'message' => 'No card were found'
                ], REST_Controller::HTTP_NOT_FOUND);
            }
        }

        else {
            if ($id <= 0)
            {
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST);
            }

            $Card=$this->Card_model->get_Card($id);
            if (!empty($Card))
            {
                $this->set_response($Card, REST_Controller::HTTP_OK);
            }
            else
            {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'card could not be found'
                ], REST_Controller::HTTP_NOT_FOUND);
            }
        }

    }

    public function index_post()
    {
        $clear_pinCode=$this->post('pinCode');
        $encrypted_pin=password_hash($clear_pinCode, PASSWORD_DEFAULT);
        $add_data=array(
          'idcard'=>$this->post('idcard'),  
          'owner'=>$this->post('owner'),
          'pinCode'=>$encrypted_pin
        );
        $insert_id=$this->Card_model->add_Card($add_data);
        if($insert_id)
        {
            $message = [
                'idcard'=>$this->post('idcard'),
                'owner'=>$this->post('owner'),
                'pinCode'=>$this->post('pinCode'),
                'message' => 'Added a resource'
            ];
            $this->set_response($message, REST_Controller::HTTP_CREATED);
        }
        else
        {
            $message = [
                'idcard'=>$this->post('idcard'),
                'owner'=>$this->post('owner'),
                'pinCode'=>$this->post('pinCode'),
                'message' => 'Added a resource'
            ];
            $this->set_response($message, REST_Controller::HTTP_CREATED);
        }

    }
    public function index_put()
    {
        $id=$this->get('id');
        $update_data=array(
          'owner'=>$this->post('owner'),
          'pinCode'=>$this->post('pinCode')
        );
        $result=$this->Card_model->update_Card($id, $update_data);

        if($result)
        {
            $message = [
                'idcard' => $id,
                'owner'=>$this->post('owner'),
                'pinCode'=>$this->post('pinCode'),
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
        $result=$this->Card_model->delete_Card($id);
        if ($result)
        {
          $message = [
              'idcard' => $id,
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